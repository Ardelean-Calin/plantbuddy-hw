#include "led.h"
#include "BlueNRG1_gpio.h"
#include "FreeRTOS.h"
#include "task.h"

void vLEDInit()
{
  /* General GPIO configuration struct */
  GPIO_InitType xGPIOConfig;
  /* Init GPIO used for LED */
  /* Enable the GPIO Clock */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO, ENABLE);

  /* Configure the LED */
  xGPIOConfig.GPIO_Pin     = LED_PIN;
  xGPIOConfig.GPIO_Mode    = GPIO_Output;
  xGPIOConfig.GPIO_Pull    = ENABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = ENABLE;
  GPIO_Init(&xGPIOConfig);
  /* Put the LED off */
  GPIO_WriteBit(LED_PIN, Bit_RESET);

  /* Create tjhe FreeRTOS task */
  xTaskCreate(vLEDPeriodicTask, "StatusLED", 64, (void*)1, tskIDLE_PRIORITY + 1U, NULL);
}

void vLEDPeriodicTask(void* pvParams)
{
  for (;;)
  {
    /* Just blink the LED periodically */
    GPIO_ToggleBits(LED_PIN);
    vTaskDelay(pdMS_TO_TICKS(LED_BLINK_PERIOD));
  }
}