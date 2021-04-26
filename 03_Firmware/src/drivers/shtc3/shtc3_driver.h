#pragma once

#include "app_util.h"
#include "nrf_twi_mngr.h"
#include "shtc3_types.h"
#include <stdint.h>

#define SHTC3_I2C_ADDR 0x70

#define SHTC3_MEAS_DELAY_MS 13  // 12.1ms max as per datasheet
#define SHTC3_WKUP_DELAY_US 240 // 240us as per datasheet

// Converts to a physical integer where each value is 1/100 th of a %.
#define SHTC3_RAW_HUM_TO_PHYS(raw)  (airhum_t)(ROUNDED_DIV(10000 * (uint32_t)raw, 1 << 16))
#define SHTC3_RAW_TEMP_TO_PHYS(raw) (airtemp_t)(ROUNDED_DIV(17500 * (uint32_t)raw, 1 << 16) - 4500)

void drv_shtc3_init(nrf_twi_mngr_t* twi_mngr_ptr, airtemp_t* temperature, airhum_t* humidity);
void drv_shtc3_meas_start(void);