#include "sensors.h"
#include "app_timer.h"
#include "nrf_twi_mngr.h"
#include "opt3001_driver.h"
#include "pb_config.h"
#include "shtc3_driver.h"
#include "soilhum_driver.h"

uint32_t soilhumidity;
uint16_t airhum_raw;
uint16_t airtemp_raw;

#define SENSORS_UPDATE_PERIOD_MS 1000 // We will call the different sensor update commands every this number of ms
#define TWI_PENDING_TRANSACTIONS 3    // Size of TWI transactions queue

APP_TIMER_DEF(m_sensors_periodic_timer);                      // App timer used by this module
NRF_TWI_MNGR_DEF(m_twi_manager, TWI_PENDING_TRANSACTIONS, 0); // TWI Transaction manager

/**
 * @brief Handler for the periodic apptimer. Here we will call our measurement start commands.
 * @param[in] p_context Timer context passed whenever we started the timer.
 */
static void sensors_apptimer_handler(void* p_context)
{
    /* One by one start a new measurement. TODO: Make it smart => don't start if ongoing! */
    drv_soilhum_meas_start(&soilhumidity);
    drv_shtc3_meas_start(&airtemp_raw, &airhum_raw);
}

/**
 * @brief Initializes the app timer used by this module.
 */
static void sensors_apptimer_init(void)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* First we create an app timer that this module will use to read stuff */
    err_code = app_timer_create(&m_sensors_periodic_timer, APP_TIMER_MODE_REPEATED, sensors_apptimer_handler);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initializes the app timer used by this module.
 */
static void sensors_apptimer_start(void)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* Start the app timer */
    err_code = app_timer_start(m_sensors_periodic_timer, APP_TIMER_TICKS(SENSORS_UPDATE_PERIOD_MS), NULL);
    APP_ERROR_CHECK(err_code);
}

static void sensors_twi_mngr_init(void)
{
    nrf_drv_twi_config_t twi_config = NRF_DRV_TWI_DEFAULT_CONFIG;
    twi_config.scl                  = PIN_I2C_SCL;
    twi_config.sda                  = PIN_I2C_SDA;

    nrf_twi_mngr_init(&m_twi_manager, &twi_config);
}

/**
 * @brief Initializes the different environmental sensors of PlantBuddy.
 */
void sensors_init(void)
{
    drv_soilhum_init();
    drv_shtc3_init((nrf_twi_mngr_t*)&m_twi_manager);

    sensors_twi_mngr_init();
    // Finally, start the periodic app timer
    sensors_apptimer_init();
    sensors_apptimer_start();
}