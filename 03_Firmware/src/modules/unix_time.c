#include "unix_time.h"
#include "app_error.h"
#include <stdint.h>

/* Static variables */
static unix_time_t unix_epoch_time_s; /* current unix epoch time. */

/* Code begin */
void unix_time_init(void)
{
    ret_code_t err_code;
    unix_epoch_time_s = 0;
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
    unix_epoch_time_s = timestamp;
}

/**
 * @brief Executes every second to keep the global UNIX time.
 */
void unix_time_task()
{
    /* Just increment uptime by one second! */
    unix_epoch_time_s++;
}