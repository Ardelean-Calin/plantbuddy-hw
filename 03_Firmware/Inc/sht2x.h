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

#define SHT2X_READ_PERIOD  100 // Read a new value every 100ms
#define SHT2X_READ_DELAY   1   // The delay [ms] from measurement start to read
#define SHT2X_I2C_DATASIZE 2   // We always receive 2 bytes

/* Retreives the current temperature and humidity */
void vSHT2XPeriodicTask(void* pvParameters);

#endif