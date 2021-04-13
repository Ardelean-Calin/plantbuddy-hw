/* Nordic-specific includes */
#include "app_timer.h"
#include "nrf_twi_mngr.h"
#include "nrfx_twi.h"
/* Drivers */
#include "battery_sensor.h"
#include "opt3001_driver.h"
#include "shtc3_driver.h"
#include "soilhum_driver.h"
/* BLE Characteristics */
#include "char_pb_sensors.h"
/* Other includes */
#include "ble_cus_pb.h"
#include "pb_config.h"
#include "sensors.h"

static uint16_t      battery_voltage_mv;
static sensor_data_t sensor_data;

#ifdef RELEASE
#define SENSORS_UPDATE_PERIOD_MS 10000 // We will call the different sensor update commands every this number of ms
#elif DEBUG
#define SENSORS_UPDATE_PERIOD_MS 1000 // We will call the different sensor update commands every this number of ms
#endif
#define TWI_PENDING_TRANSACTIONS 5 // Size of TWI transactions queue

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
    char_pb_sensors_update(sensor_data);
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
    /* Initialize the different environment sensors */
    drv_shtc3_init((nrf_twi_mngr_t*)&m_twi_manager, &sensor_data.airtemp_raw, &sensor_data.airhum_raw);
    drv_opt3001_init((nrf_twi_mngr_t*)&m_twi_manager, &sensor_data.lum_flux);
    drv_soilhum_init(&sensor_data.soil_humidity);
    batt_sensor_init(&battery_voltage_mv);

    // TWI Manager is used by some sensors
    sensors_twi_mngr_init();
    // Finally, start the periodic app timer
    sensors_apptimer_init();
    sensors_apptimer_start();
    // Start an initial round of measurements
    sensors_start_measurements();
}