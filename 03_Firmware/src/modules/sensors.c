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
#include "char_sensordata.h"
/* Other includes */
#include "ble_cus_pb.h"
#include "pb_config.h"
#include "sensors.h"
#include "unix_time.h"

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
    // Current timestamp
    sensor_data.unix_epoch_time = unix_time_get_timestamp();
    // The measured variables
    sensor_data.soil_humidity = drv_soilhum_get_frequency();
    sensor_data.airhum_phys   = drv_shtc3_get_airhum();
    sensor_data.airtemp_phys  = drv_shtc3_get_airtemp();
    sensor_data.lum_flux      = drv_opt3001_get_lumflux();
    // TODO: I suggest implementing the Battery Service so that every device can read the battery level in a
    // standardized way. For that we need to read more about BAS; might need to estimate SoC here
    sensor_data.battery_mv = batt_sensor_get_voltage();
    // Update BLE characteristic
    char_sensordata_update(sensor_data);
    // Start new measurements
    sensors_start_measurements();
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
    drv_shtc3_init((nrf_twi_mngr_t*)&m_twi_manager);   // These two
    drv_opt3001_init((nrf_twi_mngr_t*)&m_twi_manager); // need i2c
    drv_soilhum_init();
    batt_sensor_init();

    // TWI Manager is used by some sensors
    sensors_twi_mngr_init();
    // Finally, start the periodic app timer
    sensors_apptimer_init();
    sensors_apptimer_start();
    // Start an initial round of measurements
    sensors_start_measurements();
}