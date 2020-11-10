
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
#include "BlueNRG1_gpio.h"
#include "BlueNRG1_i2c.h"
#include "UserConfig.h"
#include "system_bluenrg1.h"

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
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

  /* Put the LEDs off */
  GPIO_WriteBit(GPIO_Pin_4, Bit_RESET);

  /* Create our FreeRTOS tasks */
  xTaskCreate(vLEDBlinker, "LED", 64, (void*)1, tskIDLE_PRIORITY + 1U, NULL);
  vTaskStartScheduler();

  /* Infinite loop. Should never get here */
  while (1) {}
}

static void InitHardware()
{
  GPIO_InitType GPIO_InitStructure;
  I2C_InitType  I2C_InitStructure;
  /* Init GPIO used for LED */
  /* Enable the GPIO Clock */
  SysCtrl_PeripheralClockCmd(CLOCK_PERIPH_GPIO, ENABLE);

  /* Configure the LEDs */
  GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode    = GPIO_Output;
  GPIO_InitStructure.GPIO_Pull    = ENABLE; // Pull down
  GPIO_InitStructure.GPIO_HighPwr = ENABLE;
  GPIO_Init(&GPIO_InitStructure);

  /* Init I2C used for SHT2X temperature and humidity sensor */
  SysCtrl_PeripheralClockCmd(SHT2X_I2C_PERIPH_CLK, ENABLE);
  // Inits SDA and SCL pins so that they're configured for I2C
  SHT2X_Init_SCL();
  SHT2X_Init_SDA();
  // Then inits the I2C peripheral
  I2C_StructInit(&I2C_InitStructure);
  I2C_InitStructure.I2C_ClockSpeed    = SHT2X_CLK_SPEED;
  I2C_InitStructure.I2C_OperatingMode = I2C_OperatingMode_Master;
  I2C_Init(I2C1, &I2C_InitStructure);
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
