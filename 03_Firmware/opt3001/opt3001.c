#include "opt3001.h"
#include "FreeRTOS.h"
#include "i2c.h"
#include "task.h"

static eOPT3001State xCurrentState;
static uint8_t       pucRawData[2];
static uint8_t       pucMFID[2];
static uint8_t       pucDID[2];
/* Constant variables */
/* The supported I2C commands */
const uint8_t OPT_REGISTER_READ_MFID = 0x7E;
const uint8_t OPT_REGISTER_READ_DID  = 0x7F;
const uint8_t OPT_REGISTER_CONFIGURE = 0x01;
const uint8_t OPT_REGISTER_LOW_LIMIT = 0x02;
const uint8_t OPT_REGISTER_RESULT    = 0x00;

/* OPT3001 Setup:
15-12b = 1100    :   Automatic-full-scale mode
11b    = 1       :   Coversion time (1 = 800ms, more accurate)
10-9b  = 01      :   Mode of conversion operation (01 = single shot)
8b     = 0       :   Overflow flag (Read-Only)
7b     = 0       :   Conversion ready field (Read-Only)
6b     = 0       :   Flag high field (Read-Only)
5b     = 0       :   Flag low field (Read-Only)
4b     = 1       :   Latch field (1 = window-style comparision operation)
3b     = 1       :   Polarity field (INT pin reports active high)
2b     = 0       :   Mask exponent field (0 = do not mask exponent)
1-0b   = 00      :   Fault count field (0 = 1 fault until interrupt)
*/
const uint8_t OPT_CMD_CONFIG[2]    = {0xCA, 0x18};
const uint8_t OPT_CMD_LOW_LIMIT[2] = {0xC0, 0x00}; // Enable EOC interrupts -> not used

uint32_t ulLightIntensity;

/* Static Function prototypes */
static void     vOPTPeriodicTask(void* pvParams); /* Retreives the current light intensity*/
static void     vOPTDoneISR(void* pvParams);
static uint32_t ulOPTResultToLux(uint8_t* result);

void vOPT3001Init()
{
  xCurrentState = OPT_STATE_INIT;

  /* Create our FreeRTOS tasks */
  xTaskCreate(vOPTPeriodicTask, "OPT3001", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
}

static void vOPTPeriodicTask(void* pvParams)
{
  TickType_t xLastWakeTime;

  const TickType_t xFrequency = pdMS_TO_TICKS(OPT_TASK_PERIOD);
  xLastWakeTime               = xTaskGetTickCount();
  for (;;)
  {
    // This module uses I2C
    xSemaphoreTake(hI2CSemaphore, portMAX_DELAY);
    switch (xCurrentState)
    {
    case OPT_STATE_INIT:
      // Read the MFID
      i2c_read_register(OPT_I2C_ADDRESS, OPT_REGISTER_READ_MFID, pucMFID, 2);
      // Read the DID
      i2c_read_register(OPT_I2C_ADDRESS, OPT_REGISTER_READ_DID, pucDID, 2);
      xCurrentState = OPT_STATE_CONFIGURE;
      break;

    case OPT_STATE_CONFIGURE:
      // Configure interrupt on every measurement
      i2c_write_register(OPT_I2C_ADDRESS, OPT_REGISTER_LOW_LIMIT, &OPT_CMD_LOW_LIMIT[0], 2);
      xCurrentState = OPT_STATE_START_CONVERSION;
      break;
    case OPT_STATE_START_CONVERSION:
      // Start conversion
      i2c_read_register(OPT_I2C_ADDRESS, OPT_REGISTER_CONFIGURE, pucRawData, 2);
      i2c_write_register(OPT_I2C_ADDRESS, OPT_REGISTER_CONFIGURE, &OPT_CMD_CONFIG[0], 2);
      xCurrentState = OPT_STATE_ONGOING;
      break;
    case OPT_STATE_ONGOING:
      // Do nothing, wait for conversion to be ready
      xCurrentState = OPT_STATE_RESULT;
      xSemaphoreGive(hI2CSemaphore);
      vTaskDelayUntil(&xLastWakeTime, xFrequency);
      break;
    case OPT_STATE_RESULT:
      // Result ready, read it
      // Idea: Maybe in the future we can verify that the result is truly ready with the
      // Conversion Ready flag (see configuration register)
      i2c_read_register(OPT_I2C_ADDRESS, OPT_REGISTER_RESULT, pucRawData, 2);
      // Decode result
      ulLightIntensity = ulOPTResultToLux(pucRawData);
      xCurrentState    = OPT_STATE_START_CONVERSION;
      break;

    default: break;
    }
    xSemaphoreGive(hI2CSemaphore);
  }
}

static uint32_t ulOPTResultToLux(uint8_t* result)
{
  uint32_t ulLux;

  uint8_t  exponent   = (result[0] & 0xF0) >> 4;
  uint16_t fractional = ((result[0] & 0x0F) << 8) | result[1];

  ulLux = (1 << exponent) * fractional;

  return ulLux;
}