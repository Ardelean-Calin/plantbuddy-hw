// clang-format off
#include "soilhum_sensor.h"
#include "app_config.h"
#include "nrf_drv_timer.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include <stdint.h>
// clang-format on

static const nrf_drv_timer_t m_timer0 = NRF_DRV_TIMER_INSTANCE(1);
static nrf_ppi_channel_t     m_ppi_channel1;

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
    soilhum_cfg_ppi();
    soilhum_gpio_init();
    soilhum_timer_init();
}

// State machine tick
void soilhum_sm_tick() {}