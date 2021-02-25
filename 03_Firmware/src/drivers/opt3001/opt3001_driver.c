#include "opt3001_driver.h"
#include "app_timer.h"
#include "nrf_twi_mngr.h"
#include "opt3001_types.h"

/* App timer definition */
APP_TIMER_DEF(m_opt3001_apptimer);

/* Static function definition */
static void drv_opt3001_apptimer_handler(void* p_context);
static void drv_opt3001_apptimer_init(void);
static void drv_opt3001_meas_done_cb(ret_code_t result, void* p_user_data);

/* Static and constant variables */
static nrf_twi_mngr_t*  twi_mngr;
static OPT3001_result_t opt3001_meas_result;
static luminous_flux_t* luxPhys;

/* TWI Transaction definitions */
// Measurement start transaction
OTP3001_WRITE_TRANSFER_DEF(OPT3001_CONFIG, 0x00CA, meas_start_transfer); // Single-shot, 800ms conversion time
OPT3001_TRANSACTION_DEF(meas_start, meas_start_transfer, NULL);

// Data extraction transaction (after measurement is done)
OTP3001_READ_TRANSFER_DEF(OPT3001_RESULT, &opt3001_meas_result, data_extract_trans);
OPT3001_TRANSACTION_DEF(data_extract, data_extract_trans, drv_opt3001_meas_done_cb);
/* TWI Transaction definitions END */

/**
 * @brief Handler for the apptimer used by this module. Runs after OPT3001 finished integrating.
 * @param[in] p_context Context passed to this handled. Not used.
 */
static void drv_opt3001_apptimer_handler(void* p_context)
{
    UNUSED_PARAMETER(p_context);
    // Lux conversion is ready, so now we extract the values
    nrf_twi_mngr_schedule(twi_mngr, &data_extract);
}

/**
 * @brief Initializes this module's apptimer.
 */
static void drv_opt3001_apptimer_init(void)
{
    app_timer_create(&m_opt3001_apptimer, APP_TIMER_MODE_SINGLE_SHOT, drv_opt3001_apptimer_handler);
}

/**
 * @brief Called when the TWI Manager read all our data for us. Here we extract the physical Lux value.
 * @param[in] result Parameter used to check for transaction errors.
 * @param[in] p_user_data Pointer to some user data passed by the TWI Manager.
 */
static void drv_opt3001_meas_done_cb(ret_code_t result, void* p_user_data)
{
    UNUSED_PARAMETER(result);
    UNUSED_PARAMETER(p_user_data);

    // Calculate the physical lux value from the raw one
    *luxPhys =
        (luminous_flux_t)((uint32_t)(1 << opt3001_meas_result.exponent) * (uint32_t)(opt3001_meas_result.reading)) /
        100;
}

/**
 * @brief Initializes this module.
 * @param[in] twi_mngr_ptr Pointer to the global TWI Transaction Manager
 * @param[in] lux_ptr Pointer to a memory location store for the lux value
 */
void drv_opt3001_init(nrf_twi_mngr_t* twi_mngr_ptr, luminous_flux_t* lux_ptr)
{
    twi_mngr = twi_mngr_ptr;
    luxPhys  = lux_ptr;

    drv_opt3001_apptimer_init(); // Init apptimer used for timing i2c transactions
}

/**
 * @brief Starts measurement of the light intensity using OPT3001.
 * @param[in] twi_mngr_ptr Pointer to the global TWI Transaction Manager
 */
void drv_opt3001_meas_start(void)
{
    nrf_twi_mngr_schedule(twi_mngr, &meas_start); // Writing to the configure register starts the operation

    app_timer_start(m_opt3001_apptimer, APP_TIMER_TICKS(OPT3001_CFG_CONVERSION_TIME_MS), NULL);
}