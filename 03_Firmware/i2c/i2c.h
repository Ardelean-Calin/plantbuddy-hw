#ifndef PB_I2C_H__
#define PB_I2C_H__

#include "FreeRTOS.h"
#include "semphr.h"

/* Defines for I2C configuration */
#define SHTC3_I2C_CLK_SPEED  100000 // A measly 100kHz for now
#define SHTC3_I2C_INSTANCE   I2C1
#define SHTC3_I2C_PERIPH_CLK CLOCK_PERIPH_I2C1 // We use I2C1 for our sensor
#define SHTC3_I2C_PIN_SDA    GPIO_Pin_13
#define SHTC3_I2C_PIN_SCL    GPIO_Pin_12
#define SHTC3_I2C_DATASIZE   3 // We always receive 3 bytes

#define SHTC3_Init_SCL() GPIO_InitI2c1ClkPin12()
#define SHTC3_Init_SDA() GPIO_InitI2c1DataPin13()

extern SemaphoreHandle_t hI2CSemaphore;

/* Public function definitions */
void i2c_init(void);
int  i2c_write(uint8_t addr, const uint8_t* data, uint8_t len);
int  i2c_read(uint8_t addr, uint8_t* data, uint8_t len);
void i2c_write_register(uint8_t addr, uint8_t reg, const uint8_t* data, uint8_t len);
void i2c_read_register(uint8_t addr, uint8_t reg, uint8_t* dest, uint8_t len);

#endif