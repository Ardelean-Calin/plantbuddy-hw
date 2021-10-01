#include "ltr303.h"
#include "app_scheduler.h"
#include "app_timer.h"
#include "i2c_common.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_twi.h"
#include "nrf_log.h"
#include "pb_config.h"

/* Two apptimers used for timing single-shot events */
APP_TIMER_DEF(m_single_shot);

/* Static functions */
static void ltr303_interrupt_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
static void ltr303_lux_rawtophys();
static void ltr303_timer_expired_handler(void* p_context);

static uint8_t         rx_buffer[] = {0, 0, 0, 0};
static uint16_t        ch1_raw;
static uint16_t        ch0_raw;
static luminous_flux_t lux_phys;

static eLTR303_STATE currentState;
static eLTR303_STATE nextState;

void ltr303_init()
{
    ret_code_t err_code;

    currentState = LTR303_STARTUP;
    ch1_raw      = 0U;
    ch0_raw      = 0U;

    /* Configure external interrupt */
    if (!nrf_drv_gpiote_is_init())
    {
        err_code = nrf_drv_gpiote_init();
        APP_ERROR_CHECK(err_code);
    }
    nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    in_config.pull                       = NRF_GPIO_PIN_PULLUP;

    err_code = nrf_drv_gpiote_in_init(PIN_INTERRUPT_LUX, &in_config, ltr303_interrupt_handler);
    APP_ERROR_CHECK(err_code);

    nrf_drv_gpiote_in_event_enable(PIN_INTERRUPT_LUX, true);

    app_timer_create(&m_single_shot, APP_TIMER_MODE_SINGLE_SHOT, ltr303_timer_expired_handler);
}

/**
 * @brief LTR303 State machine tick function.
 */
void ltr303_sm_tick()
{
    uint8_t*   p_rx_buffer;
    ret_code_t ret;
    uint8_t    byte;

    switch (currentState)
    {
    case LTR303_SM_IDLE:
        break;
    case LTR303_STARTUP:
        /* Invoke a SW reset */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000010);
        /* Here we need to wait 100ms until sensor startup. */
        nextState    = LTR303_READ_IDS;
        currentState = LTR303_SM_IDLE;
        app_timer_start(m_single_shot, APP_TIMER_TICKS(100), &nextState);
        break;

    case LTR303_READ_IDS:
        p_rx_buffer = &rx_buffer[0];
        byte        = LTR303_PART_ID;
        /* Part ID and MFC ID */
        i2c_read_register8(LTR303_ADDRESS, LTR303_PART_ID, p_rx_buffer++);
        i2c_read_register8(LTR303_ADDRESS, LTR303_MFC_ID, p_rx_buffer);

        if ((rx_buffer[0] != 0xA0) || (rx_buffer[1] != 0x05))
        {
            NRF_LOG_ERROR("Communication error with LTR303.")
            APP_ERROR_HANDLER(0);

            // Some kind of error
            currentState = LTR303_ERROR;
        }

        currentState = LTR303_CONFIG;
        break;

    case LTR303_CONFIG:
        /* Set interrupt thresholds */
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_UP_0, 0x00);
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_UP_1, 0x00);

        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_LOW_0, 0xFF);
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_LOW_1, 0xFF);

        /* Activate interrupts */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_INTERRUPT, 0b00000010);

        /* Go to wait for measurement */
        currentState = LTR303_START;
        break;

    case LTR303_START:
        /* Set gain and go to active measurement mode */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000001);
        currentState = LTR303_WAIT_MEAS;
        break;

    case LTR303_WAIT_MEAS:
        /* Do nothing */
        break;

    case LTR303_MEAS_DONE:
        /* Receive the two ALS values */
        p_rx_buffer = &rx_buffer[0];
        /* Channel 1 */
        i2c_read_register8(LTR303_ADDRESS, LTR303_DATA_CH1_0, p_rx_buffer++);
        i2c_read_register8(LTR303_ADDRESS, LTR303_DATA_CH1_1, p_rx_buffer++);
        ch1_raw = rx_buffer[0] + (rx_buffer[1] << 8);
        /* Channel 0 */
        i2c_read_register8(LTR303_ADDRESS, LTR303_DATA_CH0_0, p_rx_buffer++);
        i2c_read_register8(LTR303_ADDRESS, LTR303_DATA_CH0_1, p_rx_buffer);
        ch0_raw = rx_buffer[0] + (rx_buffer[1] << 8);

        /* Data extraction to convert to physical lux value */
        ltr303_lux_rawtophys();

        /* Go to sleep/standby */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000000);

        currentState = LTR303_SLEEP;
        break;

    case LTR303_SLEEP:
        nextState    = LTR303_START;
        currentState = LTR303_SM_IDLE;
        app_timer_start(m_single_shot, APP_TIMER_TICKS(LTR303_MEAS_PERIOD_MS), &nextState);
        break;

    case LTR303_ERROR:
        NRF_LOG_ERROR("LTR303_ERROR");
        currentState = LTR303_STARTUP;
        break;

    default:
        break;
    }
}

luminous_flux_t ltr303_get_luminous_flux()
{
    return (luminous_flux_t)lux_phys;
}

static void ltr303_lux_rawtophys()
{
    float ratio = ch1_raw / (ch0_raw + ch1_raw);
    if (ratio < 0.45)
    {
        lux_phys = (1.7743 * ch0_raw + 1.1059 * ch1_raw) / 1 / 1 / LTR303_PFACTOR;
    }
    else if ((ratio < 0.64) && (ratio >= 0.45))
    {
        lux_phys = (4.2785 * ch0_raw - 1.9548 * ch1_raw) / 1 / 1 / LTR303_PFACTOR;
    }
    else if ((ratio < 0.85) && (ratio >= 0.64))
    {
        lux_phys = (0.5926 * ch0_raw + 0.1185 * ch1_raw) / 1 / 1 / LTR303_PFACTOR;
    }
    else
    {
        lux_phys = 0.0;
    }
}

static void ltr303_interrupt_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    currentState = LTR303_MEAS_DONE;
}

static void ltr303_timer_expired_handler(void* p_context)
{
    /* Set the current state to the next state */
    currentState = *((eLTR303_STATE*)p_context);
}