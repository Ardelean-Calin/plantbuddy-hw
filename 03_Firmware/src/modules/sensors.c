/* Nordic-specific includes */
#include "nrf_drv_twi.h"
/* Drivers */
#include "battery_sensor.h"
#include "ltr303.h"
#include "shtc3.h"
#include "soilhum.h"
/* BLE Characteristics */
#include "char_sensordata.h"
/* Other includes */
#include "ble_cus_pb.h"
#include "pb_config.h"
#include "sensors.h"
#include "unix_time.h"

/* TWI instance. */
static const nrf_drv_twi_t m_twi = NRF_DRV_TWI_INSTANCE(0);

static sensor_data_t sensor_data;

static void sensors_i2c_handler(nrf_drv_twi_evt_t const* p_event, void* p_context)
{
}

static void sensors_i2c_init(void)
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t twi_config = {.scl                = PIN_I2C_SCL,
                                             .sda                = PIN_I2C_SDA,
                                             .frequency          = NRF_DRV_TWI_FREQ_100K,
                                             .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
                                             .clear_bus_init     = true};

    err_code = nrf_drv_twi_init(&m_twi, &twi_config, NULL, NULL);
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&m_twi);
}

static void sensors_start_measurements(void)
{
    /* One by one start a new measurement. TODO: Make it smart => don't start if ongoing! */
    soilhum_meas_start();
    // shtc3_meas_start();
    // ltr303_meas_start();
    // batt_sensor_meas_start();
}

/**
 * @brief Initializes the different environmental sensors of PlantBuddy.
 */
void sensors_init(void)
{
    /* Initialize i2c peripheral used by sensors */
    sensors_i2c_init();
    /* Initialize the different environment sensors */
    ltr303_init(); /* Ambient light sensor */
    shtc3_init();
    soilhum_init();
    // TODO: Problem: I cannot use CSense together with SAADC => Will need to:
    // 1) Init saadc, start measurement, end measurement, deinit then =>
    // 2) Init csense, start measurement, end measurement, deinit...
    // Anyways it's not elegant, we need also some kind of semaphore mechanism
    // batt_sensor_init();

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
    sensor_data.soil_humidity = soilhum_get_frequency();
    sensor_data.airhum_phys   = shtc3_get_airhum();
    sensor_data.airtemp_phys  = shtc3_get_airtemp();
    sensor_data.lum_flux      = ltr303_get_luminous_flux();
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