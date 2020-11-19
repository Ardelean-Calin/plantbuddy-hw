#include "soilhum.h"
#include "BlueNRG1_conf.h"
#include "FreeRTOS.h"
#include "task.h"

void vSoilHumInit(void)
{
  GPIO_InitType xGPIOConfig; // General GPIO configuration
  NVIC_InitType xNVICConfig; // Interrupt configuration
  MFT_InitType  xMFTConfig;  // Multi-function timer configuration

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
}

void vSoilHumPeriodicTask(void* pvParams)
{
  TickType_t       xLastWakeTime;
  const TickType_t xFrequency = pdMS_TO_TICKS(SOILHUM_TASK_PERIOD);

  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    // TODO
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
  }
}

/* Called whenever a timer interrupt occurs */
void vSoilHumTimerInterrupt(void)
{
  // TODO
}