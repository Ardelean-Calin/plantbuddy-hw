#pragma once

#include "nrf_error.h"

/* Pin defines */
#define PIN_OUT_LEDY      15
#define PIN_INTERRUPT_LUX 14
#define PIN_UART_RX       19
#define PIN_UART_TX       20

// I2C Pins
#define PIN_I2C_SCL 12
#define PIN_I2C_SDA 11

// Charge/discharge for soil moisture measurement
#define PIN_SOILHUM_CHG  29
#define PIN_SOILHUM_MEAS 28
// Discharge pad is on analog input 4
#define AIN_4                    4
#define PIN_SOILHUM_MEAS_CH_MASK (1UL << AIN_4)
