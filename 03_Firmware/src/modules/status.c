#include "nrf_drv_gpiote.h"
#include "pb_config.h"
#include <stdint.h>

#ifdef DEBUG
#define BLINK_EVERY_N_100ms 5
#elif RELEASE
#define BLINK_EVERY_N_100ms 100
#endif

/* Static functions */
static void status_gpiote_init(void);

/* Static variables */
static uint32_t invocation;

/**
 * @brief Initialize the status module
 */
void status_init()
{
    invocation = 0;
    // Initialize GPIOTE for this module
    status_gpiote_init();
}

void status_task()
{
    /* Toggle LEDs to indicate status. Runs in thread mode! */
    if (invocation++ % BLINK_EVERY_N_100ms == 0)
        nrf_drv_gpiote_out_set(PIN_OUT_LEDY);
    else
        nrf_drv_gpiote_out_clear(PIN_OUT_LEDY);
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
