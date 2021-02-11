#include "soilhum_driver.h"
#include "app_config.h"
#include "app_timer.h"
#include "nordic_common.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include <stdint.h>

#define MEAS_DURATION_MS 100

// App timer used by this module
APP_TIMER_DEF(m_soilhum_sm_timer);

static const nrf_drv_timer_t m_timer0 = NRF_DRV_TIMER_INSTANCE(1);
static nrf_ppi_channel_t     m_ppi_channel1;

static void drv_soilhum_apptimer_handler(void* p_context);
static void drv_soilhum_apptimer_init(void);
static void drv_soilhum_cfg_ppi(void);
static void drv_soilhum_gpio_init(void);
static void drv_soilhum_timer_init(void);

/**
 * @brief Handler for the single-shot timer.
 * @param[in] p_context Timer context passed whenever we started the timer. In this case we expect destination pointer
 * to be passed here.
 */
static void drv_soilhum_apptimer_handler(void* p_context)
{
    UNUSED_PARAMETER(p_context);

    // Holds the measured frequency
    uint32_t* freqPointer = (uint32_t*)p_context;

    // The elapsed time is done! Disable 555 timer
    nrf_drv_gpiote_out_set(PIN_OUT_SOILHUM_ENABLE);
    // Then read counter value
    uint32_t counter_value = nrf_drv_timer_capture_get(&m_timer0, NRF_TIMER_CC_CHANNEL0);
    // And calculate and store the frequency in a variable!
    *freqPointer = (APP_TIMER_TICKS(1000) * counter_value) / APP_TIMER_TICKS(MEAS_DURATION_MS);
}

/**
 * @brief Initializes the app timer used by this module.
 */
static void drv_soilhum_apptimer_init(void)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* First we create an app timer that this module will use to read stuff */
    err_code = app_timer_create(&m_soilhum_sm_timer, APP_TIMER_MODE_SINGLE_SHOT, drv_soilhum_apptimer_handler);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initializes the PPI to be used by GPIOTE module to increment counter.
 */
static void drv_soilhum_cfg_ppi(void)
{
    nrfx_err_t err_code = NRF_SUCCESS;

    /* Configure 1st available PPI channel to increment counter rising edge of GPIO
     */
    err_code = nrf_drv_ppi_channel_alloc(&m_ppi_channel1);
    APP_ERROR_CHECK(err_code);
    err_code = nrf_drv_ppi_channel_assign(m_ppi_channel1,
                                          nrf_drv_gpiote_in_event_addr_get(PIN_IN_SOILHUM_FREQ),
                                          nrf_drv_timer_task_address_get(&m_timer0, NRF_TIMER_TASK_COUNT));

    // Enable PPI channel
    err_code = nrf_drv_ppi_channel_enable(m_ppi_channel1);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initializes the two GPIO pins used by this driver.
 */
static void drv_soilhum_gpio_init(void)
{
    // Here we need to configure two pins:
    // - One input pin for frequency measurement.
    // - One output pin for enabling the frequency measurement.
    nrf_drv_gpiote_in_config_t freqConfig = GPIOTE_CONFIG_IN_SENSE_LOTOHI(true);
    freqConfig.pull                       = NRF_GPIO_PIN_NOPULL;

    nrf_drv_gpiote_in_init(PIN_IN_SOILHUM_FREQ, &freqConfig, NULL);

    nrf_drv_gpiote_out_config_t enableConfig = GPIOTE_CONFIG_OUT_SIMPLE(true);
    nrf_drv_gpiote_out_init(PIN_OUT_SOILHUM_ENABLE, &enableConfig);
}

/**
 * @brief Initializes the internal timer module as a counter.
 */
static void drv_soilhum_timer_init(void)
{
    // Here we configure a timer as counter
    nrf_drv_timer_config_t timerConfig = NRF_DRV_TIMER_DEFAULT_CONFIG;
    timerConfig.bit_width              = TIMER_BITMODE_BITMODE_32Bit;
    timerConfig.mode                   = TIMER_MODE_MODE_Counter;

    nrf_drv_timer_init(&m_timer0, &timerConfig, NULL);
    nrf_drv_timer_enable(&m_timer0);
}

/**
 * @brief Initializes the Soil Humidity driver.
 */
void drv_soilhum_init(void)
{
    drv_soilhum_gpio_init();
    drv_soilhum_timer_init();
    drv_soilhum_cfg_ppi();
    drv_soilhum_apptimer_init();
}

/**
 * @brief Reads the soil humidity and puts the resulting value inside the given variable
 * @param[in] freq Pointer to a memory location where the driver shall store the measurement result.
 */
void drv_soilhum_read(uint32_t* freq)
{
    ret_code_t err_code = NRF_SUCCESS;

    /* Enable 555 timer and counter */
    nrf_drv_timer_clear(&m_timer0);
    nrf_drv_gpiote_out_clear(PIN_OUT_SOILHUM_ENABLE);
    /* Start the app timer as well */
    app_timer_start(m_soilhum_sm_timer, APP_TIMER_TICKS(MEAS_DURATION_MS), (void*)freq);
    APP_ERROR_CHECK(err_code);
}