#pragma once

/* Analog channels used by our application */
#define AIN_2 2
#define AIN_4 4

/* Pin defines */
#define PIN_INTERRUPT_LUX 14

// I2C Pins
#define PIN_I2C_SCL 13
#define PIN_I2C_SDA 11

// Charge/discharge for soil moisture measurement
#define PIN_SOILHUM_CHG  29
#define PIN_SOILHUM_MEAS 28
// Discharge pad is on analog input 4
#define PIN_SOILHUM_MEAS_CH_MASK (1UL << AIN_4)

// Battery voltage sensing pin
#define BATTV_ANALOG_CHANNEL NRF_SAADC_INPUT_AIN2
