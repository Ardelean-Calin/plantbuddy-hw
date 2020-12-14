#include "soilhum.h"
#include "BlueNRG1_conf.h"
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t    hSoilHumEvtCntrIsrTask; // The handler of our event interrupt processing task
TaskHandle_t    hSoilHumTimCntrIsrTask; // The handler of our internal counter interrupt processing
uint32_t        ulSoilHumFrequency;     // Frequency of the square wave received from the 555 timer
static uint16_t uwTimEvtOverflowCtr;    // Number of overflows of the event timer
static uint16_t uwTimIntOverflowCtr;    // Number of overflows of the internal timer
static volatile uint32_t ulTimIntValue; // An internal timer which we use to keep precise time

static void vSoilHumPeriodicTask(void* pvParams);
static void vSoilHumEvtTimerInterrupt(void* pvParams);
static void vSoilHumIntTimerInterrupt(void* pvParams);

/**
 * @brief  Initializes GPIO and Timers necessary for the soil humidity measurement module.
 */
void vSoilHumInit(void)
{
  GPIO_InitType xGPIOConfig; // General GPIO configuration
  NVIC_InitType xNVICConfig; // Interrupt configuration
  MFT_InitType  xMFTConfig;  // Multi-function timer configuration

  uwTimEvtOverflowCtr = 0U;
  uwTimIntOverflowCtr = 0U;
  ulSoilHumFrequency  = 0U;

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
  /*
   * We have two timers configured:
   *  - Timer A is in internal counting mode where it counts with a frequency of 1MHz
   *  - Timer B is in external event counting mode, it counts edge transitions on pin 11
   *
   * The ratio of these two values gives us the frequency of the signal.
   */
  xMFTConfig.MFT_Mode      = MFT_MODE_3;
  xMFTConfig.MFT_Clock1    = MFT_PRESCALED_CLK;
  xMFTConfig.MFT_Clock2    = MFT_EXTERNAL_EVENT;
  xMFTConfig.MFT_Prescaler = 16 - 1;
  xMFTConfig.MFT_CRA       = 0xFFFF;
  xMFTConfig.MFT_CRB       = 0xFFFF;
  MFT_Init(MFT1, &xMFTConfig);

  /* Set the counter values */
  MFT_SetCounter(MFT1, 0xFFFF, 0xFFFF);

  /* Enable MFT Interrupts */
  // Used by external event counter
  xNVICConfig.NVIC_IRQChannel                   = MFT1B_IRQn;
  xNVICConfig.NVIC_IRQChannelPreemptionPriority = LOW_PRIORITY;
  xNVICConfig.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&xNVICConfig);
  // Used by internal timer
  xNVICConfig.NVIC_IRQChannel                   = MFT1A_IRQn;
  xNVICConfig.NVIC_IRQChannelPreemptionPriority = LOW_PRIORITY;
  xNVICConfig.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&xNVICConfig);

  /* Select pin 11 for external event capture */
  MFT_SelectCapturePin(MFT1_TIMERB, SOILHUM_PIN_IN_POS);
  MFT_TnEDGES(MFT1, MFT_RISING, MFT_RISING);
  MFT_EnableIT(MFT1, MFT_IT_TNA | MFT_IT_TND, ENABLE);
  /* Start MFT timer */
  MFT_Cmd(MFT1, ENABLE);

  /* Create the tasks used by this module */
  xTaskCreate(vSoilHumPeriodicTask, "SoilHum", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vSoilHumEvtTimerInterrupt,
              "SoilHumExIsrH",
              64,
              NULL,
              tskIDLE_PRIORITY + 2U,
              &hSoilHumEvtCntrIsrTask);
  xTaskCreate(vSoilHumIntTimerInterrupt,
              "SoilHumIntIsrH",
              64,
              NULL,
              tskIDLE_PRIORITY + 2U,
              &hSoilHumTimCntrIsrTask);
}

/**
 * @brief  Periodic task that starts measurement of soil humidity.
 */
static void vSoilHumPeriodicTask(void* pvParams)
{
  uint16_t   uwCurrExtTimVal;      // Current external timer value (can be maximum 65535)
  uint16_t   uwCurrIntTimVal;      // Current internal timer value (can be maximum 65535)
  uint32_t   ulSensorSigEdgeCount; // Number of rising edges since last task invocation
  TickType_t xLastWakeTime;

  const TickType_t xFrequency  = pdMS_TO_TICKS(SOILHUM_TASK_PERIOD);
  const TickType_t xMeasPeriod = pdMS_TO_TICKS(SOILHUM_MEAS_PERIOD);

  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    /* Reset timer count */
    uwTimEvtOverflowCtr = 0U;
    uwTimIntOverflowCtr = 0U;
    MFT_SetCounter(MFT1, 0xFFFF, 0xFFFF);
    /* Enable soil humidity measurement */
    GPIO_WriteBit(SOILHUM_PIN_ENABLE, Bit_RESET);
    /* Wait 100ms. Uses the second counter to count in parallel. Much more precise this way */
    vTaskDelay(xMeasPeriod);
    /* Disable soil humidity measurement. Preserve power */
    GPIO_WriteBit(SOILHUM_PIN_ENABLE, Bit_SET);

    /* Read counters/timers and calculate frequency by calculating how many events were registered
     * in a precise amount of time*/
    uwCurrIntTimVal = 0xFFFFU - MFT_GetCounter1(MFT1);
    uwCurrExtTimVal = 0xFFFFU - MFT_GetCounter2(MFT1);
    /* This is the total number of timer edges we got since last invocation */
    ulSensorSigEdgeCount = (uwTimEvtOverflowCtr << 16) + uwCurrExtTimVal;
    ulTimIntValue        = (uwTimIntOverflowCtr << 16) + uwCurrIntTimVal;

    ulSoilHumFrequency = (uint64_t)(((uint64_t)ulSensorSigEdgeCount * 1000000) / ulTimIntValue);
    /* Measurement done. IDLE task takes over and goes to sleep */
  }
}

/**
 * @brief  This interrupt is called whenever the external event counter overflows.
 */
static void vSoilHumEvtTimerInterrupt(void* pvParams)
{
  uint32_t ulNotifiedValue;
  for (;;)
  {
    ulNotifiedValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    // This way we know how many overflows we had between periodic task calls
    uwTimEvtOverflowCtr += (uint16_t)ulNotifiedValue;
  }
}

/**
 * @brief  This interrupt is called whenever the internal 1MHz timer overflows.
 */
static void vSoilHumIntTimerInterrupt(void* pvParams)
{
  uint32_t ulNotifiedValue;
  for (;;)
  {
    ulNotifiedValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    // This way we know how many overflows we had between periodic task calls
    uwTimIntOverflowCtr += (uint16_t)ulNotifiedValue;
  }
}