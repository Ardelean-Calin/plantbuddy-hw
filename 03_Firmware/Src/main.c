
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
#include "ble.h"
#include "i2c.h"
#include "led.h"
#include "memory_map.h"
#include "opt3001.h"
#include "shtc3.h"
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
SemaphoreHandle_t hI2CSemaphore;
/* Private functions ---------------------------------------------------------*/
static void RemapVectorTableToRam(void);

/**
 * @brief  Main program code.
 * @param  None
 * @retval None
 */
int main(void)
{
  /* This is where the magic happens, I remap the Interrupt Vector Table to RAM, then in SystemInit
   * I specify to the microcontroller that it shall use the table found in RAM and not in flash */
  RemapVectorTableToRam();
  /* System initialization function */
  SystemInit();

  /* Module init */
  vBLEInit(); // For some reason, BLE needs to be first...
  vLEDInit();
  vSHTC3Init();
  vSoilHumInit();
  vOPT3001Init();

  /* Hardware modules init */
  i2c_init();

  /* Init FreeRTOS structures used by multiple modules */
  hI2CSemaphore = xSemaphoreCreateBinary();
  xSemaphoreGive(hI2CSemaphore);

  /* Tasks were created by module initializer. Now start scheduler */
  vTaskStartScheduler();

  /* Infinite loop. Should never get here */
  while (1) {}
}

static void RemapVectorTableToRam()
{

  // Copy interrupt vector table to the RAM.
  volatile uint32_t* VectorTable      = (volatile uint32_t*)&__vector_table_ram_start__;
  uint32_t           ui32_VectorIndex = 0;

  for (ui32_VectorIndex = 0; ui32_VectorIndex < 48; ui32_VectorIndex++)
  {
    VectorTable[ui32_VectorIndex] =
        *(__IO uint32_t*)((uint32_t)&__approm_start__ + (ui32_VectorIndex << 2));
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
