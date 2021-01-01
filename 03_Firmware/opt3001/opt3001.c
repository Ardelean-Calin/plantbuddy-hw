#include "opt3001.h"
#include "FreeRTOS.h"
#include "i2c.h"
#include "task.h"

TaskHandle_t hOPTDoneIsrTask; // The handler of our event interrupt processing task

static eOPT3001State xCurrentState;
static uint8_t       pucRawData[2];
static uint8_t       pucMFID[2];
static uint8_t       pucDID[2];
/* Constant variables */
/* The supported I2C commands */
const uint8_t OPT_READ_MFID   = 0x7E;
const uint8_t OPT_READ_DID    = 0x7F;
const uint8_t OPT_CONFIGURE   = 0x01;
const uint8_t OPT_READ_RESULT = 0x00;
// const uint8_t OPT_CMD_CONFIG[2] = {0b11001010, 0b000};
// const uint8_t OPT_CMD_WAKEUP[2]               = {0x35, 0x17};
// const uint8_t OPT_CMD_SLEEP[2]                = {0xB0, 0x98};
// const uint8_t OPT_CMD_START_MEAS_STRETCH[2]   = {0x7C, 0xA2};
// const uint8_t OPT_CMD_START_MEAS_NOSTRETCH[2] = {0x78, 0x66};
// const uint8_t OPT_CMD_RESET[2]                = {0x80, 0x5D};

/* Static Function prototypes */
static void vOPTPeriodicTask(void* pvParams); /* Retreives the current light intensity*/
static void vOPTDoneISR(void* pvParams);

void vOPT3001Init()
{
  GPIO_InitType       xGPIOConfig;       // General GPIO configuration
  NVIC_InitType       xNVICConfig;       // Interrupt configuration
  GPIO_EXTIConfigType xGPIOExtItrConfig; // GPIO external interrupt configuration

  /* Configure the OPT3001 interrupt */
  xGPIOConfig.GPIO_Pin     = OPT3001_PIN_INTERRUPT;
  xGPIOConfig.GPIO_Mode    = GPIO_Input;
  xGPIOConfig.GPIO_Pull    = ENABLE; // Pull up, internal
  xGPIOConfig.GPIO_HighPwr = DISABLE;
  GPIO_Init(&xGPIOConfig);

  xNVICConfig.NVIC_IRQChannel                   = GPIO_IRQn;
  xNVICConfig.NVIC_IRQChannelPreemptionPriority = LOW_PRIORITY;
  xNVICConfig.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&xNVICConfig);

  // Configure external interrupt
  xGPIOExtItrConfig.GPIO_Pin      = OPT3001_PIN_INTERRUPT;
  xGPIOExtItrConfig.GPIO_IrqSense = GPIO_IrqSense_Edge;
  xGPIOExtItrConfig.GPIO_Event    = GPIO_Event_Low;
  GPIO_EXTIConfig(&xGPIOExtItrConfig);
  /* Clear pending interrupt */
  GPIO_ClearITPendingBit(OPT3001_PIN_INTERRUPT);
  /* Enable the interrupt */
  GPIO_EXTICmd(OPT3001_PIN_INTERRUPT, ENABLE);

  xCurrentState = OPT_STATE_INIT;

  /* Create our FreeRTOS tasks */
  xTaskCreate(vOPTPeriodicTask, "OPT3001", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vOPTDoneISR, "SoilHumExIsrH", 64, NULL, tskIDLE_PRIORITY + 2U, &hOPTDoneIsrTask);
}

static void vOPTPeriodicTask(void* pvParams)
{
  for (;;)
  {
    // This module uses I2C
    xSemaphoreTake(hI2CSemaphore, portMAX_DELAY);
    switch (xCurrentState)
    {
    case OPT_STATE_INIT:
      // Read the MFID
      i2c_write(OPT_I2C_ADDRESS, &OPT_READ_MFID, 1);
      i2c_read(OPT_I2C_ADDRESS, pucMFID, 2);
      i2c_write(OPT_I2C_ADDRESS, &OPT_READ_DID, 1);
      i2c_read(OPT_I2C_ADDRESS, pucDID, 2);
      break;

    default: break;
    }
    xSemaphoreGive(hI2CSemaphore);
    vTaskDelay(100);
  }
}

/**
 * @brief  This interrupt is called whenever the OPT3001 finishes a measurement
 */
static void vOPTDoneISR(void* pvParams)
{
  uint32_t ulNotifiedValue;
  for (;;) { ulNotifiedValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY); }
}