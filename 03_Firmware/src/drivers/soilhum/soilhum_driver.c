#include "soilhum_driver.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_drv_csense.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "nrf_log.h"
#include "pb_config.h"
#include "soilhum_types.h"
#include <stdint.h>

// Holds the measured frequency
static soilhum_t frequency;

/* Static functions */
static void drv_soilhum_csense_handler(nrf_drv_csense_evt_t* p_event_struct);

/**
 * @brief Handler called when a capacitive measurement is done.
 * @param[in] p_event_struct Struct containing information regarding the measurement.
 */
static void drv_soilhum_csense_handler(nrf_drv_csense_evt_t* p_event_struct)
{
    volatile uint16_t value = p_event_struct->read_value;
    // Don't need to check channels since we only use one.
    // TODO: Change name and type of "frequency" variable
    // TODO2: Does it make sense to use app scheduler here? This function is really short... Maybe if I add
    // a "convert to capacitance" function, I would want that to not be executed in interrupt mode
    frequency = value;
    NRF_LOG_INFO("Measured soil humidity: %u", frequency);
}

/**
 * @brief Initializes the Soil Humidity driver.
 */
void drv_soilhum_init()
{
    frequency = 0;
    ret_code_t err_code;

    nrf_drv_csense_config_t csense_config;

#if USE_COMP == 0
    csense_config.output_pin = PIN_SOILHUM_CHG;
#endif

    err_code = nrf_drv_csense_init(&csense_config, drv_soilhum_csense_handler);
    APP_ERROR_CHECK(err_code);

    nrf_drv_csense_channels_enable(PIN_SOILHUM_MEAS_CH_MASK);

    drv_soilhum_meas_start();
}

/**
 * @brief Reads the soil humidity and puts the resulting value inside the given variable
 */
void drv_soilhum_meas_start(void)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* Start a capacitive measurement! */
    err_code = nrf_drv_csense_sample();
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Returns the latest soil humidity (actually, a frequency proportional to it).
 */
soilhum_t drv_soilhum_get_frequency(void)
{
    return frequency;
}