#include "shtc3.h"
#include "BlueNRG1_i2c.h"
#include "FreeRTOS.h"
#include "i2c.h"
#include "main.h"
#include "task.h"

/* Constant variables */
/* The supported I2C commands */
const uint8_t SHTC3_CMD_WAKEUP[2]               = {0x35, 0x17};
const uint8_t SHTC3_CMD_SLEEP[2]                = {0xB0, 0x98};
const uint8_t SHTC3_CMD_START_MEAS_STRETCH[2]   = {0x7C, 0xA2};
const uint8_t SHTC3_CMD_START_MEAS_NOSTRETCH[2] = {0x78, 0x66};
const uint8_t SHTC3_CMD_RESET[2]                = {0x80, 0x5D};

/* Static Function prototypes */
static void
vSHTC3PeriodicTask(void* pvParameters); /* Retreives the current temperature and humidity */

/* Variables used by this module */
uint16_t           uwSHTC3Temp;
uint16_t           uwSHTC3RH;
static uint8_t     pucRawData[6];
static eSHTC3State xCurrentState;

/**
 * @brief Initialises this module.
 */
void vSHTC3Init(void)
{
  uwSHTC3Temp   = 0;
  uwSHTC3RH     = 0;
  xCurrentState = SHTC3_STATE_INIT;

  /* Create our FreeRTOS tasks */
  xTaskCreate(vSHTC3PeriodicTask, "SHTC3", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
}

/**
 * @brief The periodic task that gathers temperature & relative humidity data from the sensor.
 */
static void vSHTC3PeriodicTask(void* pvParameters)
{
  TickType_t       xLastWakeTime;
  const TickType_t xFrequency = pdMS_TO_TICKS(SHTC3_TASK_PERIOD);
  TickType_t       xTimeDelay = 0;

  xLastWakeTime = xTaskGetTickCount();

  for (;;)
  {

    xSemaphoreTake(hI2CSemaphore, portMAX_DELAY);

    switch (xCurrentState)
    {
    case SHTC3_STATE_INIT:
      // On init, send a reset command
      xCurrentState = SHTC3_STATE_WAKEUP;

      i2c_write(SHTC3_I2C_ADDRESS, SHTC3_CMD_RESET, SHTC3_I2C_TXPACKET_LEN);
      xTimeDelay = pdMINIMUM_DELAY(1); // Delay in ms
      break;

    case SHTC3_STATE_WAKEUP:
      xCurrentState = SHTC3_STATE_MEAS_START;

      i2c_write(SHTC3_I2C_ADDRESS, SHTC3_CMD_WAKEUP, SHTC3_I2C_TXPACKET_LEN);
      xTimeDelay = pdMINIMUM_DELAY(1);
      break;

    case SHTC3_STATE_MEAS_START:
      xCurrentState = SHTC3_STATE_MEAS_READ;

      i2c_write(SHTC3_I2C_ADDRESS, SHTC3_CMD_START_MEAS_NOSTRETCH, SHTC3_I2C_TXPACKET_LEN);
      xTimeDelay = pdMINIMUM_DELAY(20);
      break;

    case SHTC3_STATE_MEAS_READ:
      xCurrentState = SHTC3_STATE_MEAS_SLEEP;

      // Read temperature (2 bytes + CRC) & humidity (2 bytes + CRC)
      i2c_read(SHTC3_I2C_ADDRESS, &pucRawData[0], SHTC3_I2C_RXPACKET_LEN);
      /* Extract the raw temperature and humidity values => to be converted to phys by mobile phone
       */
      uwSHTC3Temp = (pucRawData[0] << 8) + pucRawData[1];
      uwSHTC3RH   = (pucRawData[3] << 8) + pucRawData[4];

      xTimeDelay = 0;
      break;

    case SHTC3_STATE_MEAS_SLEEP:
      xCurrentState = SHTC3_STATE_WAKEUP;

      i2c_write(SHTC3_I2C_ADDRESS, SHTC3_CMD_SLEEP, SHTC3_I2C_TXPACKET_LEN);
      // Delay until the next periodic call of the state machine
      vTaskDelayUntil(&xLastWakeTime, xFrequency);
      break;

    default: break;
    }

    xSemaphoreGive(hI2CSemaphore);
    vTaskDelay(xTimeDelay);
  }
}