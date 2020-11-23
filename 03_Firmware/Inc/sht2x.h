#ifndef SHT2X_H__
#define SHT2X_H__

#define SHT2X_I2C_ADDRESS 0x40 // The I2C Address of an SHT2x

/* The supported I2C commands */
#define SHT2X_CMD_WRITE_USER_REG   0xE6
#define SHT2X_CMD_READ_USER_REG    0xE7
#define SHT2X_CMD_RESET            0xFE
#define SHT2X_CMD_READ_TEMP_HOLD   0xE3
#define SHT2X_CMD_READ_RH_HOLD     0xE5
#define SHT2X_CMD_READ_TEMP_NOHOLD 0xF3
#define SHT2X_CMD_READ_RH_NOHOLD   0xF5

/* Defines for I2C configuration */
#define SHT2X_I2C_CLK_SPEED  100000 // A measly 100kHz for now
#define SHT2X_I2C_INSTANCE   I2C1
#define SHT2X_I2C_PERIPH_CLK CLOCK_PERIPH_I2C1 // We use I2C1 for our sensor
#define SHT2X_I2C_PIN_SDA    GPIO_Pin_13
#define SHT2X_I2C_PIN_SCL    GPIO_Pin_12
#define SHT2X_I2C_DATASIZE   2 // We always receive 2 bytes

#define SHT2X_Init_SCL() GPIO_InitI2c1ClkPin12()
#define SHT2X_Init_SDA() GPIO_InitI2c1DataPin13()

/* Here we define the delays between start of measurement and reading of values */
#define SHT2X_TEMP_14BIT_DELAY 100 // Time in [ms] between start of measurement and read. (min 85)
#define SHT2X_RH_14BIT_DELAY   100 // Time in [ms] between start of measurement and read. (min 29)

#define I2C_Operation_Read_PERIOD 1000 // Read a new value every 1000ms

typedef enum
{
  SHT2X_RES_RH12_T14 = 0b00,
  SHT2X_RES_RH08_T12,
  SHT2X_RES_RH10_T13,
  SHT2X_RES_RH11_T11,
} tSHT2XMeasResolution;

/* Initialization code */
void vSHT2XInit(void);
/* Retreives the current temperature and humidity */
void vSHT2XPeriodicTask(void* pvParameters);

#endif