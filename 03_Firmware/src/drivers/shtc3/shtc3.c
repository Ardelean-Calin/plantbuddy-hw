#include "shtc3.h"
#include "app_error.h"
#include "app_timer.h"
#include "i2c_common.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "pb_config.h"
#include "shtc3_lut.h"

APP_TIMER_DEF(m_shtc3_apptimer);

/* The three commands used by our SHTC3 driver */
static const uint16_t SHTC3_CMD_SOFT_RESET = 0x5D80;
static const uint16_t SHTC3_CMD_GOTO_SLEEP = 0x98B0;
static const uint16_t SHTC3_CMD_WKUP       = 0x1735;
static const uint16_t SHTC3_READ_ID        = 0xC8EF; // Manufacturer specific ID. Expected: 2 bytes + 1 byte checksum
static const uint16_t SHTC3_START_MEAS     = 0x6678; // Starts a measurement (T first then H)

static eSHTC3_State currentState;
static eSHTC3_State nextState;

/* Locally-used, static variables */
static airtemp_t shtc3_temp;
static airhum_t  shtc3_hum;
static uint8_t   shtc3_read_buffer[6];
static uint8_t   shtc3_product_id_buffer[4];
static uint16_t  shtc3_product_id;

/* Locally-used, static functions */
static void    shtc3_apptimer_handler(void* p_context);
static void    shtc3_update_phys();
static uint8_t shtc3_calculate_crc8(uint8_t* pBuffer, uint8_t length);

/**
 * @brief Driver initialization function.
 */
void shtc3_init()
{
    ret_code_t err_code = NRF_SUCCESS;

    /* First we create an app timer that this module will use to read stuff */
    err_code = app_timer_create(&m_shtc3_apptimer, APP_TIMER_MODE_SINGLE_SHOT, shtc3_apptimer_handler);
    APP_ERROR_CHECK(err_code);

    /* Then we initialize our other variables. */
    currentState = SHTC3_SM_RESET;
    nextState    = SHTC3_SM_RESET;
    shtc3_temp   = 0;
    shtc3_hum    = 0;
}

/**
 * @brief State machine tick.
 */
void shtc3_sm_tick()
{
    switch (currentState)
    {
    case SHTC3_SM_IDLE:
        /* code */
        break;

    case SHTC3_SM_RESET:
        /* Issues a software reset */
        i2c_write_u16(SHTC3_I2C_ADDR, SHTC3_CMD_SOFT_RESET);
        nrf_delay_us(SHTC3_WKUP_DELAY_US);
        currentState = SHTC3_SM_STARTUP;
        break;

    case SHTC3_SM_STARTUP:
        /* Issue the wakeup command */
        i2c_write_u16(SHTC3_I2C_ADDR, SHTC3_CMD_WKUP);
        nrf_delay_us(SHTC3_WKUP_DELAY_US);
        currentState = SHTC3_SM_READ_ID;
        break;

    case SHTC3_SM_READ_ID:
        /* Check if a sensor is connected by reading the ID register. */
        i2c_write_u16(SHTC3_I2C_ADDR, SHTC3_READ_ID);
        i2c_read_bytes(SHTC3_I2C_ADDR, shtc3_product_id_buffer, 3);
        shtc3_product_id = (shtc3_product_id_buffer[0] << 8) + shtc3_product_id_buffer[1];
        /* Check if communication was successful! */
        if ((shtc3_product_id & 0x83F) != 0x807)
            currentState = SHTC3_SM_ERROR;
        else
            currentState = SHTC3_SM_MEAS_START;
        break;

    case SHTC3_SM_MEAS_START:
        i2c_write_u16(SHTC3_I2C_ADDR, SHTC3_START_MEAS);
        // Turns on an application timer! This will issue a read after X milliseconds
        nextState    = SHTC3_SM_MEAS_READ;
        currentState = SHTC3_SM_IDLE;
        app_timer_start(m_shtc3_apptimer, APP_TIMER_TICKS(SHTC3_MEAS_DELAY_MS), &nextState);
        break;

    case SHTC3_SM_MEAS_READ:
        i2c_read_bytes(SHTC3_I2C_ADDR, shtc3_read_buffer, 6);
        // Decode the received data
        shtc3_update_phys();
        // Proceed further in state machine
        currentState = SHTC3_SM_GOTO_SLEEP;
        break;

    case SHTC3_SM_GOTO_SLEEP:
        i2c_write_u16(SHTC3_I2C_ADDR, SHTC3_CMD_GOTO_SLEEP);

        /* Now wait a given amount of time before taking the next measurement */
        nextState    = SHTC3_SM_STARTUP;
        currentState = SHTC3_SM_IDLE;
        app_timer_start(m_shtc3_apptimer, APP_TIMER_TICKS(SHTC3_MEAS_PERIOD_MS), &nextState);
        break;

    case SHTC3_SM_ERROR:
        NRF_LOG_ERROR("SHTC3 error. Resetting device.");
        currentState = SHTC3_SM_RESET;
        break;

    default:
        break;
    }
}

/**
 * @brief Get the latest measured air temperature.
 * @return The latest air temperature (physical)
 */
airtemp_t shtc3_get_airtemp(void)
{
    return shtc3_temp;
}

/**
 * @brief Get the latest measured air humidity.
 * @return The latest air humidity (physical)
 */
airhum_t shtc3_get_airhum(void)
{
    return shtc3_hum;
}

/**
 * @brief Handler for the single-shot timer.
 * @param[in] p_context Pointer to the next state of the state machine.
 */
static void shtc3_apptimer_handler(void* p_context)
{
    currentState = *((eSHTC3_State*)p_context);
}

/**
 * @brief Updates the physical value of air temperature and humidity.
 */
static void shtc3_update_phys()
{
    uint16_t raw_temp;
    uint16_t raw_hum;

    // We read the raw data bytes from the sensor. Now we need to process them!
    raw_temp = (shtc3_read_buffer[0] << 8) + shtc3_read_buffer[1];
    raw_hum  = (shtc3_read_buffer[3] << 8) + shtc3_read_buffer[4];

    shtc3_temp = SHTC3_RAW_TEMP_TO_PHYS(raw_temp);
    shtc3_hum  = SHTC3_RAW_HUM_TO_PHYS(raw_hum);
    NRF_LOG_INFO("Air temperature: %u", shtc3_temp);
    NRF_LOG_INFO("Air humidity: %u", shtc3_hum);
    // TODO: Checksum is the third byte of every packet, maybe check it and raise error if problem?
}

/**
 * @brief Calculates the CRC-8 according to the SHTC3 datasheet.
 */
static uint8_t shtc3_calculate_crc8(uint8_t* pBuffer, uint8_t length)
{
    uint8_t crc = 0xFF;
    while (length--)
    {
        // Simple CRC calculation using look-up table
        crc = shtc3_crc8_lookup_table[crc ^ *pBuffer++];
    }
    return crc;
}
