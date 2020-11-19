
/******************** (C) COPYRIGHT 2020 G&C ********************
 * File Name          : PlantBuddy/main.c
 * Author             : Ardelean Calin
 * Version            : V0.1
 * Date               : November-2020
 * Description        : Entry point of PlantBuddy
 *****************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "BlueNRG1.h"
#include "BlueNRG1_conf.h"
#include "BlueNRG1_it.h"
#include "UserConfig.h"
#include "led.h"
#include "sht2x.h"
#include "soilhum.h"
#include "system_bluenrg1.h"
#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Private typedefs ----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program code.
 * @param  None
 * @retval None
 */
int main(void)
{
  /* System initialization function */
  SystemInit();

  /* Module init */
  vLEDInit();
  vSHT2XInit();
  vSoilHumInit();

  /* Create our FreeRTOS tasks */
  xTaskCreate(vLEDPeriodicTask, "LED", 64, (void*)1, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vSHT2XPeriodicTask, "SHT2x", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
  xTaskCreate(vSoilHumPeriodicTask, "SHum", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);

  vTaskStartScheduler();

  /* Infinite loop. Should never get here */
  while (1) {}
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
