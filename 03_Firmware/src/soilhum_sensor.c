#include "soilhum_sensor.h"
#include "app_config.h"
#include "app_timer.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include <stdint.h>

static const nrf_drv_timer_t m_timer0 = NRF_DRV_TIMER_INSTANCE(1);
static nrf_ppi_channel_t     m_ppi_channel1;
// Previous and current call times for the timer
static uint32_t timer_start_tick;
static uint32_t timer_curr_tick;
// Holds the current state of our statemachine
static soilhum_state_t current_state;

static uint32_t frequency;

/**
 * @brief Inits the PPI to be used by GPIOTE module to increment counter
 */
static void soilhum_cfg_ppi()
{
    nrfx_err_t err_code;

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

static void soilhum_gpio_init()
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

static void soilhum_timer_init()
{
    // Here we configure a timer as counter
    nrf_drv_timer_config_t timerConfig = NRF_DRV_TIMER_DEFAULT_CONFIG;
    timerConfig.bit_width              = TIMER_BITMODE_BITMODE_32Bit;
    timerConfig.mode                   = TIMER_MODE_MODE_Counter;

    nrf_drv_timer_init(&m_timer0, &timerConfig, NULL);
    nrf_drv_timer_enable(&m_timer0);
}

void soilhum_init(void)
{
    timer_start_tick = app_timer_cnt_get();
    timer_curr_tick  = timer_start_tick;
    current_state    = IDLE;

    soilhum_gpio_init();
    soilhum_timer_init();
    soilhum_cfg_ppi();
}

// State machine tick
void soilhum_sm_tick()
{
    uint32_t counter_value      = 0;
    uint32_t elapsed_time_ticks = 0;

    switch (current_state)
    {
    case IDLE:
        timer_curr_tick    = app_timer_cnt_get();
        elapsed_time_ticks = app_timer_cnt_diff_compute(timer_curr_tick, timer_start_tick);
        if (elapsed_time_ticks >= APP_TIMER_TICKS(1000))
        {
            timer_start_tick = app_timer_cnt_get();
            /* Enable 555 timer and counter */
            nrf_drv_timer_clear(&m_timer0);
            nrf_drv_gpiote_out_clear(PIN_OUT_SOILHUM_ENABLE);
            current_state = MEASURING;
        }
        break;

    case MEASURING:
        /* Wait for a time to elapse until we have enough data in the counter */
        timer_curr_tick    = app_timer_cnt_get();
        elapsed_time_ticks = app_timer_cnt_diff_compute(timer_curr_tick, timer_start_tick);
        if (elapsed_time_ticks >= APP_TIMER_TICKS(100))
        {
            // The elapsed time is done! Disable 555 timer
            nrf_drv_gpiote_out_set(PIN_OUT_SOILHUM_ENABLE);
            // Then read counter value
            counter_value = nrf_drv_timer_capture_get(&m_timer0, NRF_TIMER_CC_CHANNEL0);
            frequency     = (APP_TIMER_TICKS(1000) * counter_value) / elapsed_time_ticks;
            current_state = IDLE;
        }
        break;

    default: current_state = IDLE; break;
    }
}