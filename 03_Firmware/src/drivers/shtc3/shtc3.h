#pragma once

#include "app_util.h"
#include "nrf_twi_mngr.h"
#include <stdint.h>

/* Typedefs BEGIN */

typedef uint16_t airtemp_t;
typedef uint16_t airhum_t;

typedef enum SHTC3_State
{
    SHTC3_SM_IDLE = 0,
    SHTC3_SM_RESET,
    SHTC3_SM_READ_ID,
    SHTC3_SM_STARTUP,
    SHTC3_SM_MEAS_START,
    SHTC3_SM_MEAS_READ,
    SHTC3_SM_GOTO_SLEEP,
    SHTC3_SM_ERROR
} eSHTC3_State;

/* Typedefs END */

#define SHTC3_I2C_ADDR 0x70

#define SHTC3_MEAS_DELAY_MS  13   // 12.1ms max as per datasheet
#define SHTC3_WKUP_DELAY_US  240  // 240us as per datasheet
#define SHTC3_MEAS_PERIOD_MS 1000 // milliseconds between measurements

// Converts to a physical integer where each value is 1/100 th of a %.
#define SHTC3_RAW_HUM_TO_PHYS(raw)  (airhum_t)(ROUNDED_DIV(10000 * (uint32_t)raw, 1 << 16))
#define SHTC3_RAW_TEMP_TO_PHYS(raw) (airtemp_t)(ROUNDED_DIV(17500 * (uint32_t)raw, 1 << 16) - 4500)

void      shtc3_init();
void      shtc3_sm_tick();
airtemp_t shtc3_get_airtemp(void);
airhum_t  shtc3_get_airhum(void);