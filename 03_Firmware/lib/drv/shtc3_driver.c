#include "shtc3_driver.h"
#include "app_error.h"
#include "app_timer.h"
#include "nrf_delay.h"
#include "pb_config.h"

APP_TIMER_DEF(m_shtc3_apptimer);

/* The three commands used by our SHTC3 driver */
static const uint16_t SHTC3_CMD_GOTO_SLEEP = 0x98B0;
static const uint16_t SHTC3_CMD_WKUP       = 0x1735;
static const uint16_t SHTC3_START_MEAS     = 0x6678; // Starts a measurement (T first then H)

/* Two TWI transfers needed for waking-up the sensor and getting data from it */
nrf_twi_mngr_transfer_t const shtc3_transfer_wakeup[] = {
    NRF_TWI_MNGR_WRITE(SHTC3_I2C_ADDR, &SHTC3_CMD_WKUP, 2, 0),
};
nrf_twi_mngr_transfer_t const shtc3_transfer_startmeas[] = {
    NRF_TWI_MNGR_WRITE(SHTC3_I2C_ADDR, &SHTC3_START_MEAS, 2, 0),
};

/* Locally-used, static variables */
static nrf_twi_mngr_t* m_twi_manager_ptr;
static uint16_t*       shtc3_temp_ptr;
static uint16_t*       shtc3_hum_ptr;
static uint8_t         shtc3_read_buffer[6];

/* Locally-used, static functions */
static void drv_shtc3_apptimer_handler(void* p_context);
static void drv_shtc3_apptimer_init(void);
static void drv_shtc3_meas_done_cb(ret_code_t result, void* p_user_data);

/**
 * @brief Handler for the single-shot timer.
 * @param[in] p_context Timer context passed whenever we started the timer.
 */
static void drv_shtc3_apptimer_handler(void* p_context)
{
    UNUSED_PARAMETER(p_context);

    // Start a read transaction
    static nrf_twi_mngr_transfer_t const transfers[] = {
        NRF_TWI_MNGR_READ(SHTC3_I2C_ADDR, &shtc3_read_buffer[0], 6, 0),
        NRF_TWI_MNGR_WRITE(SHTC3_I2C_ADDR, &SHTC3_CMD_GOTO_SLEEP, 2, 0)};

    static nrf_twi_mngr_transaction_t twi_transaction = {.callback    = drv_shtc3_meas_done_cb,
                                                         .p_user_data = NULL,
                                                         .p_transfers = transfers,
                                                         .number_of_transfers =
                                                             sizeof(transfers) / sizeof(transfers[0]),
                                                         .p_required_twi_cfg = NULL};
    // Schedule a TWI transaction
    APP_ERROR_CHECK(nrf_twi_mngr_schedule(m_twi_manager_ptr, &twi_transaction));
}

/**
 * @brief Initializes the app timer used by this module.
 */
static void drv_shtc3_apptimer_init(void)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* First we create an app timer that this module will use to read stuff */
    err_code = app_timer_create(&m_shtc3_apptimer, APP_TIMER_MODE_SINGLE_SHOT, drv_shtc3_apptimer_handler);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Called when the TWI Manager read all our data for us.
 */
static void drv_shtc3_meas_done_cb(ret_code_t result, void* p_user_data)
{
    UNUSED_PARAMETER(result);
    UNUSED_PARAMETER(p_user_data);

    // We read the raw data bytes from the sensor. Now we need to process them!
    *shtc3_temp_ptr = (shtc3_read_buffer[0] << 8) + shtc3_read_buffer[1];
    *shtc3_hum_ptr  = (shtc3_read_buffer[3] << 8) + shtc3_read_buffer[4];
    // TODO: Checksum is the third byte of every packet, maybe check it and raise error if problem!
}

/**
 * @brief Driver initialization function.
 */
void drv_shtc3_init(nrf_twi_mngr_t* twi_mngr_ptr)
{
    m_twi_manager_ptr = twi_mngr_ptr;
    // TODO: We will implement sensor reading and writing using TWI Transaction manager!
    drv_shtc3_apptimer_init();
}

/**
 * @brief Starts a temperature and humidity measurement. Non-blocking. The total duration is approx 20ms.
 * @param[out] temperature Pointer to a memory location in which to store the read temperature.
 * @param[out] humidity Pointer to a memory location in which to store the read humidity.
 */
void drv_shtc3_meas_start(uint16_t* temperature, uint16_t* humidity)
{
    shtc3_temp_ptr = temperature;
    shtc3_hum_ptr  = humidity;

    // We need to do it with nrf_twi_mngr_perform instead of nrf_twi_mngr_schedule because of the wake-up delay!
    APP_ERROR_CHECK(nrf_twi_mngr_perform(m_twi_manager_ptr, NULL, shtc3_transfer_wakeup, 1, NULL));
    nrf_delay_us(SHTC3_WKUP_DELAY_US);
    APP_ERROR_CHECK(nrf_twi_mngr_perform(m_twi_manager_ptr, NULL, shtc3_transfer_startmeas, 1, NULL));

    // Turns on an application timer! This will issue a read after X milliseconds
    app_timer_start(m_shtc3_apptimer, APP_TIMER_TICKS(SHTC3_MEAS_DELAY_MS), NULL);
}