#include "sensors.h"
#include "app_timer.h"
#include "battery_sensor.h"
#include "ble_cus.h"
#include "char_lflux.h"
#include "nrf_drv_twi.h"
#include "nrf_twi_mngr.h"
#include "opt3001_driver.h"
#include "pb_config.h"
#include "shtc3_driver.h"
#include "soilhum_driver.h"

// TODO: This is really NOT the way to go. We need to define the characteristic here or something.
extern ble_cus_t m_cus_pb;

uint32_t soilhumidity;
uint16_t airhum_raw;
uint16_t airtemp_raw;
uint32_t lux;
uint16_t battery_voltage_mv;

#define SENSORS_UPDATE_PERIOD_MS 2000 // We will call the different sensor update commands every this number of ms
#define TWI_PENDING_TRANSACTIONS 3    // Size of TWI transactions queue

APP_TIMER_DEF(m_sensors_periodic_timer);                      // App timer used by this module
NRF_TWI_MNGR_DEF(m_twi_manager, TWI_PENDING_TRANSACTIONS, 0); // TWI Transaction manager

static void sensors_apptimer_handler(void* p_context);
static void sensors_apptimer_init(void);
static void sensors_apptimer_start(void);
static void sensors_start_measurements(void);
static void sensors_twi_mngr_init(void);

/**
 * @brief Handler for the periodic apptimer. Here we will call our measurement start commands.
 * @param[in] p_context Timer context passed whenever we started the timer.
 */
static void sensors_apptimer_handler(void* p_context)
{
    sensors_start_measurements();
    char_lflux_update(&m_cus_pb, lux);
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

/**
 * @brief Starts all sensor measurements!
 */
static void sensors_start_measurements(void)
{
    /* One by one start a new measurement. TODO: Make it smart => don't start if ongoing! */
    drv_soilhum_meas_start();
    drv_shtc3_meas_start();
    drv_opt3001_meas_start();
    batt_sensor_meas_start();
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
    drv_soilhum_init(&soilhumidity);
    drv_shtc3_init((nrf_twi_mngr_t*)&m_twi_manager, &airtemp_raw, &airhum_raw);
    drv_opt3001_init((nrf_twi_mngr_t*)&m_twi_manager, &lux);
    batt_sensor_init(&battery_voltage_mv);

    sensors_twi_mngr_init();
    // Finally, start the periodic app timer
    sensors_apptimer_init();
    sensors_apptimer_start();
    // Start an initial round of measurements
    sensors_start_measurements();
}