#include "soilhum_driver.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_drv_csense.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "pb_config.h"
#include "soilhum_types.h"
#include <stdint.h>

#define MEAS_DURATION_MS 100

// App timer used by this module
APP_TIMER_DEF(m_soilhum_sm_timer);

// Holds the measured frequency
static soilhum_t frequency;

static const nrf_drv_timer_t m_timer0 = NRF_DRV_TIMER_INSTANCE(1);
static nrf_ppi_channel_t     m_ppi_channel1;

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
    frequency = value;
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

    err_code = nrf_drv_csense_sample();
    APP_ERROR_CHECK(err_code);
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