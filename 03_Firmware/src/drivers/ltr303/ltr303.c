#include "ltr303.h"
#include "app_scheduler.h"
#include "app_timer.h"
#include "i2c_common.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_twi.h"
#include "nrf_log.h"
#include "pb_config.h"

/* Static functions */
static void ltr303_interrupt_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action);
static void ltr303_lux_rawtophys(void* p_event_data, uint16_t event_size);

static uint8_t  tx_buffer[] = {0, 0};
static uint8_t  rx_buffer[] = {0, 0, 0, 0};
static uint16_t ch1_raw;
static uint16_t ch0_raw;
static float    lux_phys;

eLTR303_STATE currentState;
uint32_t      prevTick;

void ltr303_init()
{
    ret_code_t err_code;

    currentState = LTR303_STARTUP;
    prevTick     = app_timer_cnt_get();
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
}

void ltr303_statemachine_tick()
{
    uint32_t   currTick;
    uint8_t*   p_rx_buffer;
    ret_code_t ret;
    uint8_t    byte;

    switch (currentState)
    {
    case LTR303_STARTUP:
        /* Here we need to wait 100ms until sensor startup. */
        currTick = app_timer_cnt_get();
        if (app_timer_cnt_diff_compute(currTick, prevTick) > APP_TIMER_TICKS(100))
        {
            /* 100ms have passed, sensor is initialized */
            prevTick     = currTick;
            currentState = LTR303_READ_IDS;
        }
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

        currentState = LTR303_INIT;
        break;

    case LTR303_INIT:
        /* Set interrupt thresholds */
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_UP_0, 0x00);
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_UP_1, 0x00);

        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_LOW_0, 0xFF);
        i2c_write_register8(LTR303_ADDRESS, LTR303_THRES_LOW_1, 0xFF);

        /* Activate interrupts */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_INTERRUPT, 0b00000010);

        /* Set gain and go to active measurement mode */
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000001);

        /* Go to wait for measurement */
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

        /* TODO: Schedule a data extraction routine to convert to physical lux value */
        app_sched_event_put(NULL, sizeof(NULL), ltr303_lux_rawtophys);

        /* Go to sleep/standby */
        // i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000000);

        // currentState = LTR303_SLEEP;
        currentState = LTR303_WAIT_MEAS;
        break;

        // case LTR303_SLEEP:
        //     currTick = app_timer_cnt_get();
        //     // Sleep for LTR303_MEAS_PERIOD_MS milliseconds
        //     if (app_timer_cnt_diff_compute(currTick, prevTick) > APP_TIMER_TICKS(LTR303_MEAS_PERIOD_MS))
        //     {
        //         /* Enough time has passed, start a new measurement */
        //         prevTick     = currTick;
        //         currentState = LTR303_WAKEUP;
        //     }
        //     break;

        // case LTR303_WAKEUP:
        //     currentState = LTR303_INIT;
        //     i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000001);
        //     currentState = LTR303_WAIT_MEAS;
        //     break;

    case LTR303_ERROR:
        NRF_LOG_ERROR("LTR303_ERROR");
        i2c_write_register8(LTR303_ADDRESS, LTR303_REG_CONTROL, 0b00000010);

        /* Save the previous tick as we will need to wait 100ms */
        prevTick     = app_timer_cnt_get();
        currentState = LTR303_STARTUP;
        break;

    default:
        break;
    }
}

static void ltr303_lux_rawtophys(void* p_event_data, uint16_t event_size)
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
    NRF_LOG_INFO("Measured Lux: " NRF_LOG_FLOAT_MARKER "\r\n", NRF_LOG_FLOAT(lux_phys));
}

static void ltr303_interrupt_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    currentState = LTR303_MEAS_DONE;
}