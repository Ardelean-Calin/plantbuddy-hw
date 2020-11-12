#ifndef USERCONFIG_H__
#define USERCONFIG_H__

#include "BlueNRG1_gpio.h"
#include "BlueNRG1_i2c.h"
#include "BlueNRG1_sysCtrl.h"

#define SHT2X_I2C_CLK_SPEED  100000 // A measly 100kHz for now
#define SHT2X_I2C_INSTANCE   I2C1
#define SHT2X_I2C_PERIPH_CLK CLOCK_PERIPH_I2C1 // We use I2C1 for our sensor
#define SHT2X_I2C_PIN_SDA    GPIO_Pin_13
#define SHT2X_I2C_PIN_SCL    GPIO_Pin_12

#define SHT2X_Init_SCL() GPIO_InitI2c1ClkPin12()
#define SHT2X_Init_SDA() GPIO_InitI2c1DataPin13()

#endif