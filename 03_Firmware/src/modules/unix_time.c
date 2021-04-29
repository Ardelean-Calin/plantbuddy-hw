#include "unix_time.h"
#include "app_error.h"
#include "app_timer.h"
#include <stdint.h>

/* Static functions */
static void unix_time_app_timer_1000ms_handler(void* p_context);

/* Static variables */
static unix_time_t unix_epoch_time_s;   /* current unix epoch time. */
APP_TIMER_DEF(m_periodic_timer_1000ms); /**< Handler for repeated timer used to keep UNIX epoch time. */

/* Code begin */

void unix_time_init(void)
{
    ret_code_t err_code;
    unix_epoch_time_s = 0;

    err_code = app_timer_create(&m_periodic_timer_1000ms, APP_TIMER_MODE_REPEATED, unix_time_app_timer_1000ms_handler);
    APP_ERROR_CHECK(err_code);

    err_code = app_timer_start(m_periodic_timer_1000ms, APP_TIMER_TICKS(1000), NULL); // 1000ms timer
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Get the current UNIX epoch time.
 */
unix_time_t unix_time_get_timestamp()
{
    return unix_epoch_time_s;
}

/**
 * @brief Updates the internal UNIX timestamp.
 */
void unix_time_update_timestamp(unix_time_t timestamp)
{
    app_timer_stop(m_periodic_timer_1000ms);
    unix_epoch_time_s = timestamp;
    app_timer_start(m_periodic_timer_1000ms, APP_TIMER_TICKS(1000), NULL);
}

/**
 * @brief Executes every second to keep the global UNIX time.
 */
static void unix_time_app_timer_1000ms_handler(void* p_context)
{
    /* Just increment uptime by one second! */
    unix_epoch_time_s++;
}