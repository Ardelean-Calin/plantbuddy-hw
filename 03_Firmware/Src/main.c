
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
  GPIO_InitType xGPIOConfig;
  I2C_InitType  xI2CConfig;
  /* Init GPIO used for LED */
  /* Enable the GPIO & I2C Clock */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO | SHT2X_I2C_PERIPH_CLK, ENABLE);

  /* Configure the LEDs */
  xGPIOConfig.GPIO_Pin     = GPIO_Pin_4;
  xGPIOConfig.GPIO_Mode    = GPIO_Output;
  xGPIOConfig.GPIO_Pull    = ENABLE; // Pull down
  xGPIOConfig.GPIO_HighPwr = ENABLE;
  GPIO_Init(&xGPIOConfig);

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
