
/******************** (C) COPYRIGHT 2020 G&C ********************
 * File Name          : PlantBuddy/main.c
 * Author             : Ardelean Calin
 * Version            : V0.1
 * Date               : November-2020
 * Description        : Entry point of PlantBuddy
 *****************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "main.h"
#include "BlueNRG1.h"
#include "BlueNRG1_conf.h"
#include "BlueNRG1_it.h"
#include "UserConfig.h"
#include "system_bluenrg1.h"
#include "sht2x.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
// TODO: Define this external variable
extern uint32_t ulTxBufferSHT2X;
extern uint32_t ulRxBufferSHT2X;
/* Private functions ---------------------------------------------------------*/
static void vLEDBlinker(void* pvParameters);
static void InitHardware(); /* Init hardware peripherals */

/**
 * @brief  Main program code.
 * @param  None
 * @retval None
 */
int main(void)
{
  /* System initialization function */
  SystemInit();

  /* Init the used hardware peripherals */
  InitHardware();

  /* Module init */
  vSHT2XInit();
  // vSoilHumInit();
  GPIO_WriteBit(GPIO_Pin_6, Bit_RESET);

  /* Put the LEDs off */
  GPIO_WriteBit(GPIO_Pin_4, Bit_RESET);

  /* Create our FreeRTOS tasks */
  xTaskCreate(vLEDBlinker, "LED", 64, (void*)1, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vSHT2XPeriodicTask, "SHT2x", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
  vTaskStartScheduler();

  /* Infinite loop. Should never get here */
  while (1) {}
}

static void InitHardware()
{
  GPIO_InitType xGPIOConfig; // General GPIO configuration
  I2C_InitType  xI2CConfig;  // I2C configuration
  NVIC_InitType xNVICConfig; // Interrupt configuration
  MFT_InitType  xMFTConfig;  // Multi-function timer configuration
  /* Init GPIO used for LED */
  /* Enable the GPIO & I2C Clock */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | SHT2X_I2C_PERIPH_CLK | CLOCK_PERIPH_MTFX1, ENABLE);

  /* Configure the LED */
  xGPIOConfig.GPIO_Pin     = GPIO_Pin_4;
  xGPIOConfig.GPIO_Mode    = GPIO_Output;
  xGPIOConfig.GPIO_Pull    = ENABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = ENABLE;
  GPIO_Init(&xGPIOConfig);

  /* Configure the fHumidity input */
  xGPIOConfig.GPIO_Pin     = GPIO_Pin_11;
  xGPIOConfig.GPIO_Mode    = GPIO_Input;
  xGPIOConfig.GPIO_Pull    = DISABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = DISABLE;
  GPIO_Init(&xGPIOConfig);
  /* And the fHumidity enable pin */
  xGPIOConfig.GPIO_Pin     = GPIO_Pin_6;
  xGPIOConfig.GPIO_Mode    = GPIO_Output;
  xGPIOConfig.GPIO_Pull    = DISABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = DISABLE;
  GPIO_Init(&xGPIOConfig);

  /* Configure the SHT2X i2c pins */
  // Inits SDA and SCL pins so that they're configured for I2C
  SHT2X_Init_SCL();
  SHT2X_Init_SDA();
  // Then inits the I2C peripheral
  I2C_StructInit(&xI2CConfig);
  xI2CConfig.I2C_ClockSpeed    = SHT2X_I2C_CLK_SPEED;
  xI2CConfig.I2C_OperatingMode = I2C_OperatingMode_Master;
  I2C_Init(SHT2X_I2C_INSTANCE, &xI2CConfig);
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MSK);

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

  MFT_SelectCapturePin(MFT1_TIMERB, 11); // 11 is GPIO11 => we don't use the GPIO_Pin_11 define here
  MFT_TnEDGES(MFT1, MFT_RISING, MFT_RISING);
  MFT_EnableIT(MFT1, MFT_IT_TND, ENABLE);
  /* Start MFT timer */
  MFT_Cmd(MFT1, ENABLE);
}

static void vLEDBlinker(void* pvParameters)
{
  /* The parameter value is expected to be 1 as 1 is passed in the
  pvParameters value in the call to xTaskCreateStatic(). */
  configASSERT((uint32_t)pvParameters == 1UL);

  for (;;)
  {
    /* Task code goes here. */
    GPIO_ToggleBits(GPIO_Pin_4);
    vTaskDelay(pdMS_TO_TICKS(500U));
  }
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line
     number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1) {}
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
