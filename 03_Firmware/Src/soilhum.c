#include "soilhum.h"
#include "BlueNRG1_conf.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t xSoilHumItrTaskHandler; // The handler of our interrupt processing task
uint16_t     uwOverflowCtr;          // Number of overflows since the last periodic task call
uint32_t     ulSensorSigFrequency;   // Frequency of the square wave received from the 555 timer

void vSoilHumInit(void)
{
  GPIO_InitType xGPIOConfig; // General GPIO configuration
  NVIC_InitType xNVICConfig; // Interrupt configuration
  MFT_InitType  xMFTConfig;  // Multi-function timer configuration

  uwOverflowCtr        = 0U;
  ulSensorSigFrequency = 0U;

  /* Enable the GPIO & MFT Clock */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | CLOCK_PERIPH_MTFX1, ENABLE);

  /* Init GPIO used for Soil Humidity Measurement */
  /* Configure the fHumidity input */
  xGPIOConfig.GPIO_Pin     = SOILHUM_PIN_IN;
  xGPIOConfig.GPIO_Mode    = GPIO_Input;
  xGPIOConfig.GPIO_Pull    = DISABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = DISABLE;
  GPIO_Init(&xGPIOConfig);
  /* And the fHumidity enable pin */
  xGPIOConfig.GPIO_Pin     = SOILHUM_PIN_ENABLE;
  xGPIOConfig.GPIO_Mode    = GPIO_Output;
  xGPIOConfig.GPIO_Pull    = DISABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = DISABLE;
  GPIO_Init(&xGPIOConfig);

  /* Enable soil humidity measurement via 555 timer */
  GPIO_WriteBit(SOILHUM_PIN_ENABLE, Bit_RESET);

  /* Configure timers */
  /* Soil humidity measurement using MFT */
  xMFTConfig.MFT_Mode   = MFT_MODE_3;
  xMFTConfig.MFT_Clock1 = MFT_NO_CLK;
  xMFTConfig.MFT_Clock2 = MFT_EXTERNAL_EVENT;
  xMFTConfig.MFT_CRA    = 0xFFFF;
  xMFTConfig.MFT_CRB    = 0xFFFF;
  MFT_Init(MFT1, &xMFTConfig);

  /* Set the counter values */
  MFT_SetCounter(MFT1, 0xFFFF, 0xFFFF);

  /* Enable MFT Interrupts */
  xNVICConfig.NVIC_IRQChannel                   = MFT1B_IRQn;
  xNVICConfig.NVIC_IRQChannelPreemptionPriority = LOW_PRIORITY;
  xNVICConfig.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&xNVICConfig);

  /* Select pin 11 for timer capture */
  MFT_SelectCapturePin(MFT1_TIMERB, SOILHUM_PIN_IN_POS);
  MFT_TnEDGES(MFT1, MFT_RISING, MFT_RISING);
  MFT_EnableIT(MFT1, MFT_IT_TND, ENABLE);
  /* Start MFT timer */
  MFT_Cmd(MFT1, ENABLE);

  /* Create the tasks used by this module */
  xTaskCreate(vSoilHumPeriodicTask, "SoilHum", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vSoilHumTimerInterrupt,
              "SoilHumItr",
              64,
              NULL,
              tskIDLE_PRIORITY + 2U,
              &xSoilHumItrTaskHandler);
}

/* Runs every X milliseconds and measures the frequency of the soil humidity sensor */
void vSoilHumPeriodicTask(void* pvParams)
{
  uint16_t   uwCurrTimVal;         // Current timer value (can be maximum 65535)
  uint32_t   ulSensorSigEdgeCount; // Number of rising edges since last task invocation
  TickType_t xLastWakeTime;

  const TickType_t xFrequency = pdMS_TO_TICKS(SOILHUM_TASK_PERIOD);

  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    /* Put business logic here */

    uwCurrTimVal = 0xFFFFU - MFT_GetCounter2(MFT1);
    /* This is the total number of signals we got since last invocation */
    ulSensorSigEdgeCount = (uwOverflowCtr << 16) + uwCurrTimVal;
    ulSensorSigFrequency = ulSensorSigEdgeCount * 1000 / SOILHUM_TASK_PERIOD;

    /* End of business logic */
    /* Reset timer count */
    uwOverflowCtr = 0U;
    MFT_SetCounter2(MFT1, 0xFFFF);
  }
}

/* Called whenever a timer interrupt occurs */
void vSoilHumTimerInterrupt(void* pvParams)
{
  uint32_t ulNotifiedValue;
  for (;;)
  {
    ulNotifiedValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    // This way we know how many overflows we had between periodic task calls
    uwOverflowCtr += (uint16_t)ulNotifiedValue;
  }
}