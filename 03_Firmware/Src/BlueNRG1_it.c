/**
******************************************************************************
* @file    GPIO/IOToggle/BlueNRG1_it.c
* @author  RF Application Team
* @version V1.0.0
* @date    September-2015
* @brief   Main Interrupt Service Routines.
*          This file provides template for all exceptions handler and
*          peripherals interrupt service routine.
******************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "BlueNRG1_it.h"
#include "BlueNRG1_conf.h"
#include "FreeRTOS.h"
#include "bluenrg1_stack.h"
#include "semphr.h"
#include "task.h"
#include <stdint.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
// These two handles are defined in the soilhum module and point to interrupt processing tasks
extern TaskHandle_t hSoilHumEvtCntrIsrTask;
extern TaskHandle_t hSoilHumTimCntrIsrTask;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
 * @brief  This function handles NMI exception.
 */
void NMI_Handler(void)
{
  while (1)
    ;
}

/**
 * @brief  This function handles Hard Fault exception.
 */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
    ;
}

/******************************************************************************/
/*                 BlueNRG-1 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (system_bluenrg1.c).                                               */
/******************************************************************************/

extern SemaphoreHandle_t radioActivitySemaphoreHandle;

void Blue_Handler(void)
{
  // BaseType_t xHigherPriorityTaskWoken;

  RAL_Isr();

  /* Unblock BTLE_StackTick(). */
  // xSemaphoreGiveFromISR(radioActivitySemaphoreHandle, &xHigherPriorityTaskWoken);
  // /* A context switch should be performed if xHigherPriorityTaskWoken is equal to pdTRUE. */
  // portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

/**
 * @brief  This function handles MFTB interrupt request.
 * @param  None
 * @retval None
 */
void MFT1B_Handler(void)
{
  BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;

  if ((MFT_StatusIT(MFT1, MFT_IT_TND) != RESET))
  {
    /* Clear the interrupt */
    MFT_ClearIT(MFT1, MFT_IT_TND);
    /* Delegate processing of timer underflow to task */
    vTaskNotifyGiveFromISR(hSoilHumEvtCntrIsrTask, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
  }
}

/**
 * @brief  This function handles MFTA interrupt request.
 * @param  None
 * @retval None
 */
void MFT1A_Handler(void)
{
  BaseType_t xHigherPriorityTaskWoken;
  xHigherPriorityTaskWoken = pdFALSE;

  if ((MFT_StatusIT(MFT1, MFT_IT_TNA) != RESET))
  {
    /* Clear the interrupt */
    MFT_ClearIT(MFT1, MFT_IT_TNA);
    /* Delegate processing of timer underflow to task */
    vTaskNotifyGiveFromISR(hSoilHumTimCntrIsrTask, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
  }
}

/**
 * @}
 */

/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
