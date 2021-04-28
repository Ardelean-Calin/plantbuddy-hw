#include "app_scheduler.h"
#include "app_timer.h"
#include "nrf_drv_gpiote.h"
#include "pb_config.h"
#include <stdint.h>

#ifdef DEBUG
#define BLINK_EVERY_N_100ms 2
#elif RELEASE
#define BLINK_EVERY_N_100ms 100
#endif

APP_TIMER_DEF(m_periodic_timer_100ms);  /**< Handler for repeated timer used to blink LEDs. */
APP_TIMER_DEF(m_periodic_timer_1000ms); /**< Handler for repeated timer used to keep UNIX epoch time. */

/* Static functions */
static void status_app_timer_100ms_handler(void* p_context);
static void status_app_timer_1000ms_handler(void* p_context);
static void status_app_timers_init(void);
static void status_app_timers_start(void);
static void status_gpiote_init(void);

/* Static variables */
static uint32_t invocation;
static uint32_t unix_epoch_time_s; /* current unix epoch time. TODO: update to uint64_t before 7 february 2106! */

/**
 * @brief Initialize the status module
 */
void status_init()
{
    invocation        = 0;
    unix_epoch_time_s = 0;
    // Initialize GPIOTE for this module
    status_gpiote_init();

    status_app_timers_init();
    status_app_timers_start();
}

/**
 * @brief Get the current UNIX epoch time.
 */
uint32_t status_get_timestamp()
{
    return unix_epoch_time_s;
}

/**
 * @brief Updates the internal UNIX timestamp.
 */
void status_update_timestamp(uint32_t timestamp)
{
    app_timer_stop(m_periodic_timer_1000ms);
    unix_epoch_time_s = timestamp;
    app_timer_start(m_periodic_timer_1000ms, APP_TIMER_TICKS(1000), NULL);
}

/**
 * @brief Executes every 100ms to check wether LED needs to be turned on or off.
 */
static void status_app_timer_100ms_handler(void* p_context)
{
    /* Toggle LEDs to indicate status. Runs in thread mode! */
    if (invocation++ % BLINK_EVERY_N_100ms == 0)
        nrf_drv_gpiote_out_set(PIN_OUT_LEDY);
    else
        nrf_drv_gpiote_out_clear(PIN_OUT_LEDY);
}

/**
 * @brief Executes every second to keep the global UNIX time.
 */
static void status_app_timer_1000ms_handler(void* p_context)
{
    /* Just increment uptime by one second! */
    unix_epoch_time_s++;
}

/**
 * @brief Create an app timer that blinks our LED
 */
static void status_app_timers_init()
{
    ret_code_t err_code;

    // Create timers
    err_code = app_timer_create(&m_periodic_timer_100ms, APP_TIMER_MODE_REPEATED, status_app_timer_100ms_handler);
    APP_ERROR_CHECK(err_code);
    err_code = app_timer_create(&m_periodic_timer_1000ms, APP_TIMER_MODE_REPEATED, status_app_timer_1000ms_handler);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Starts the previously created timers with given periodicity.
 */
static void status_app_timers_start()
{
    ret_code_t err_code;

    // Start timers
    err_code = app_timer_start(m_periodic_timer_100ms, APP_TIMER_TICKS(100), NULL); // 100ms timer
    APP_ERROR_CHECK(err_code);
    err_code = app_timer_start(m_periodic_timer_1000ms, APP_TIMER_TICKS(1000), NULL); // 1000ms timer
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

    // Configure output pins
    nrf_drv_gpiote_out_init(PIN_OUT_LEDY, &config1);
}
