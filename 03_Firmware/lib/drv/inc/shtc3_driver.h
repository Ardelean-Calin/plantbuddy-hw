#pragma once

#include "nrf_twi_mngr.h"
#include <stdint.h>

#define SHTC3_I2C_ADDR 0x70

#define SHTC3_MEAS_DELAY_MS 13  // 12.1ms max as per datasheet
#define SHTC3_WKUP_DELAY_US 240 // 240us as per datasheet

void drv_shtc3_init(nrf_twi_mngr_t* twi_mngr);
void drv_shtc3_meas_start(uint16_t* raw_temp_ptr, uint16_t* raw_hum_ptr);