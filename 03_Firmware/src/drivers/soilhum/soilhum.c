#include "soilhum.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf.h"
#include "nrf_drv_csense.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "nrf_log.h"
#include "pb_config.h"
#include "soilhum.h"
#include <stdint.h>

APP_TIMER_DEF(m_soilhum_apptimer);

// Holds the measured frequency
static soilhum_t      frequency;
static eSoilHum_State currentState;
static eSoilHum_State nextState;

/* Static functions */
static void soilhum_csense_handler(nrf_drv_csense_evt_t* p_event_struct);
static void soilhum_apptimer_handler(void* p_context);

/**
 * @brief Initializes the Soil Humidity driver.
 */
void soilhum_init()
{
    ret_code_t              err_code;
    nrf_drv_csense_config_t csense_config;

    frequency    = 0;
    currentState = SoilHum_SM_MEASURE;
    nextState    = SoilHum_SM_MEASURE;

#if USE_COMP == 0
    csense_config.output_pin = PIN_SOILHUM_CHG;
#endif

    err_code = nrf_drv_csense_init(&csense_config, soilhum_csense_handler);
    APP_ERROR_CHECK(err_code);

    nrf_drv_csense_channels_enable(PIN_SOILHUM_MEAS_CH_MASK);

    /* First we create an app timer that this module will use to read stuff */
    err_code = app_timer_create(&m_soilhum_apptimer, APP_TIMER_MODE_SINGLE_SHOT, soilhum_apptimer_handler);
    APP_ERROR_CHECK(err_code);
}

void soilhum_sm_tick(void)
{
    ret_code_t err_code = NRF_SUCCESS;
    switch (currentState)
    {
    case SoilHum_SM_IDLE:
        break;

    case SoilHum_SM_MEASURE:
        /* Start a capacitive measurement! */
        err_code = nrf_drv_csense_sample();
        APP_ERROR_CHECK(err_code);

        /* Wait until done. */
        currentState = SoilHum_SM_IDLE;
        nextState    = SoilHum_SM_MEASURE;
        app_timer_start(m_soilhum_apptimer, APP_TIMER_TICKS(SOILHUM_MEAS_PERIOD_MS), &nextState);
        break;

    default:
        break;
    }
}

/**
 * @brief Returns the latest soil humidity (actually, a frequency proportional to it).
 */
soilhum_t soilhum_get_frequency(void)
{
    return frequency;
}

/**
 * @brief Handler called when a capacitive measurement is done.
 * @param[in] p_event_struct Struct containing information regarding the measurement.
 */
static void soilhum_csense_handler(nrf_drv_csense_evt_t* p_event_struct)
{
    volatile uint16_t value = p_event_struct->read_value;
    // Don't need to check channels since we only use one.
    // TODO: Change name and type of "frequency" variable
    // TODO2: Does it make sense to use app scheduler here? This function is really short... Maybe if I add
    // a "convert to capacitance" function, I would want that to not be executed in interrupt mode
    frequency = value;
}

/**
 * @brief State machine helper to schedule state transitions in the future.
 */
static void soilhum_apptimer_handler(void* p_context)
{
    currentState = *((eSoilHum_State*)p_context);
}