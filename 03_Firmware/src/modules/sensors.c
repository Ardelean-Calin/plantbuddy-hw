/* Nordic-specific includes */
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

#define TWI_PENDING_TRANSACTIONS 5                            // Size of TWI transactions queue
NRF_TWI_MNGR_DEF(m_twi_manager, TWI_PENDING_TRANSACTIONS, 0); // TWI Transaction manager

static sensor_data_t sensor_data;

static void sensors_twi_mngr_init(void)
{
    nrf_drv_twi_config_t twi_config = NRF_DRV_TWI_DEFAULT_CONFIG;
    twi_config.scl                  = PIN_I2C_SCL;
    twi_config.sda                  = PIN_I2C_SDA;

    nrf_twi_mngr_init(&m_twi_manager, &twi_config);
}

static void sensors_start_measurements(void)
{
    /* One by one start a new measurement. TODO: Make it smart => don't start if ongoing! */
    // drv_soilhum_meas_start();
    drv_shtc3_meas_start();
    drv_opt3001_meas_start();
    batt_sensor_meas_start();
}

/**
 * @brief Initializes the different environmental sensors of PlantBuddy.
 */
void sensors_init(void)
{
    /* Initialize the different environment sensors */
    drv_shtc3_init((nrf_twi_mngr_t*)&m_twi_manager);   // These two
    drv_opt3001_init((nrf_twi_mngr_t*)&m_twi_manager); // need i2c
    // drv_soilhum_init();
    batt_sensor_init();

    // TWI Manager is used by some sensors
    sensors_twi_mngr_init();

    // As soon as PlantBuddy goes live, start a first measurement... This one is unfortunately not logged, though.
    sensors_start_measurements();
}

/**
 * @brief Starts all sensor measurements!
 */
void sensors_task(void)
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

    sensors_start_measurements();
}

/**
 * @brief Return the most recent sensor data.
 */
void sensors_get_latest(sensor_data_t* p_dest)
{
    *p_dest = sensor_data;
}