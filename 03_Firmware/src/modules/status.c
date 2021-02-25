#include "app_scheduler.h"
#include "app_timer.h"
#include "nrf_drv_gpiote.h"
#include "pb_config.h"

#ifndef DEBUG
#define BLINK_EVERY_N_100ms 50
#else
#define BLINK_EVERY_N_100ms 2
#endif

APP_TIMER_DEF(m_periodic_timer_100ms); /**< Handler for repeated timer used to blink LEDs. */

/* Static functions */
static void status_app_timer_handler(void* p_context);
static void status_app_timer_init(void);
static void status_app_timer_start(void);
static void status_gpiote_init(void);

static uint32_t invocation;

static void status_app_timer_handler(void* p_context)
{
    /* Toggle LEDs to indicate status. Runs in thread mode! */
    if (invocation++ % BLINK_EVERY_N_100ms == 0)
        nrf_drv_gpiote_out_set(PIN_OUT_LEDY);
    else
        nrf_drv_gpiote_out_clear(PIN_OUT_LEDY);
}

/**
 * @brief Create an app timer that blinks our LED
 */
static void status_app_timer_init()
{
    ret_code_t err_code;

    // Create timers
    err_code = app_timer_create(&m_periodic_timer_100ms, APP_TIMER_MODE_REPEATED, status_app_timer_handler);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Starts the previously created timers with given periodicity.
 */
static void status_app_timer_start()
{
    ret_code_t err_code;

    // Start timers
    err_code = app_timer_start(m_periodic_timer_100ms, APP_TIMER_TICKS(100), NULL); // 100ms timer
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initializes this module's used GPIOTE's with the proper configuration.
 */
static void status_gpiote_init(void)
{
    ret_code_t err_code;
    // Only initialize driver if it's not already initialized.
    if (!nrf_drv_gpiote_is_init())
    {
        err_code = nrf_drv_gpiote_init();
        APP_ERROR_CHECK(err_code);
    }

    // TODO: This should not be here but in some separate "status.c" module
    nrf_drv_gpiote_out_config_t config1 = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(false);
    nrf_drv_gpiote_out_config_t config2 = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(false);

    // Configure output pins
    nrf_drv_gpiote_out_init(PIN_OUT_LEDY, &config1);
    nrf_drv_gpiote_out_init(PIN_OUT_LEDR, &config2);
}

/**
 * @brief Initialize the status module
 */
void status_init()
{
    invocation = 0;
    // Initialize GPIOTE for this module
    status_gpiote_init();

    status_app_timer_init();
    status_app_timer_start();
}