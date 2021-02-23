#include "battery_sensor.h"
#include "app_error.h"
#include "app_scheduler.h"
#include "nrf_drv_saadc.h"

nrf_saadc_value_t* p_voltage;

static nrf_saadc_value_t m_buffer_pool[1][SAADC_SAMPLES_IN_BUFFER];

/* Static function definitions */
static void batt_sensor_convert_voltage(void* p_event_data, uint16_t event_size);
static void batt_sensor_saadc_callback(nrf_drv_saadc_evt_t const* p_event);
static void batt_sensor_saadc_init(void);

/**
 * @brief Function called by app scheduler which reads the ADC value and resets the ADC.
 * @param[in] p_event_data Pointer passed by the user.
 * @param[in] event_size Size of the data referenced by the passed pointer.
 */
static void batt_sensor_convert_voltage(void* p_event_data, uint16_t event_size)
{
    UNUSED_PARAMETER(event_size);

    nrf_drv_saadc_evt_t const* p_event = (nrf_drv_saadc_evt_t const*)p_event_data;
    nrf_drv_saadc_buffer_convert(p_event->data.done.p_buffer, SAADC_SAMPLES_IN_BUFFER);
    *p_voltage = BATT_SENSOR_RAW_TO_PHYS(p_event->data.done.p_buffer[0]);
    nrf_drv_saadc_uninit();
}

/**
 * @brief Called when ADC finished conversion.
 * @param[in] p_event Pointer to the ADC event which contains all relevant data.
 */
static void batt_sensor_saadc_callback(nrf_drv_saadc_evt_t const* p_event)
{
    if (p_event->type == NRF_DRV_SAADC_EVT_DONE)
    {
        app_sched_event_put(p_event, sizeof(nrf_drv_saadc_evt_t), batt_sensor_convert_voltage);
    }
}

/**
 * @brief Inits the ADC.
 */
static void batt_sensor_saadc_init(void)
{
    ret_code_t                 err_code;
    nrf_saadc_channel_config_t channel_config = NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(NRF_SAADC_INPUT_AIN2);
    channel_config.reference                  = NRF_SAADC_REFERENCE_INTERNAL;
    channel_config.gain                       = NRF_SAADC_GAIN1_6;
    channel_config.burst                      = NRF_SAADC_BURST_ENABLED;

    err_code = nrf_drv_saadc_init(NULL, batt_sensor_saadc_callback);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_saadc_channel_init(0, &channel_config);
    err_code = nrf_drv_saadc_buffer_convert(
        m_buffer_pool[0], SAADC_SAMPLES_IN_BUFFER); // Set SAADC buffer 1. The SAADC will start to write to this buffer
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initializes the battery voltage sensor.
 * @param[in] ptr_voltage Pointer where to put the converted ADC voltage.
 */
void batt_sensor_init(uint16_t* ptr_voltage)
{
    p_voltage = ptr_voltage;
}

/**
 * @brief Starts a battery voltage measurement using the ADC.
 */
void batt_sensor_meas_start(void)
{
    batt_sensor_saadc_init();
    // Start ADC sampling!
    nrf_drv_saadc_sample();
}