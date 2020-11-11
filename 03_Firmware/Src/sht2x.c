#include "sht2x.h"
#include "BlueNRG1_i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "UserConfig.h"

static void vSHT2XReadTemp(uint16_t* puwTemperature);

void vSHT2XPeriodicTask(void* pvParameters)
{
  TickType_t        xLastWakeTime;
  const TickType_t  xFrequency = pdMS_TO_TICKS(SHT2X_READ_PERIOD);
  volatile uint16_t uwTemperature; // Will store the read temperature

  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    /* Run periodically */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    vSHT2XReadTemp(&uwTemperature);
  }
}

static void vSHT2XReadTemp(uint16_t* puwTemperature)
{
  I2C_TransactionType xI2CTransaction;
  xI2CTransaction.Address       = SHT2X_I2C_ADDRESS;
  xI2CTransaction.Operation     = I2C_Operation_Write;
  xI2CTransaction.AddressType   = I2C_AddressType_7Bit;
  xI2CTransaction.StartByte     = I2C_StartByte_Disable;
  xI2CTransaction.StopCondition = I2C_StopCondition_Enable;
  xI2CTransaction.Length        = 1;

  /* To read the temperature from SHT2X, we need to do the following transactions: */
  /* 1) Write I2C address & command to start temperature measurement */
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);
  I2C_FillTxFIFO(SHT2X_I2C_INSTANCE, SHT2X_CMD_READ_TEMP_HOLD);
  /* Check write */
  do
  {
    if (I2C_OP_ABORTED == I2C_GetStatus(SHT2X_I2C_INSTANCE))
      while (1)
        ;

  } while (I2C_GetITStatus(SHT2X_I2C_INSTANCE, I2C_IT_MTDWS) == RESET);

  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MTDWS);

  /* 2) Wait at least 20us */
  // vTaskDelay(pdMS_TO_TICKS(SHT2X_READ_DELAY));
  /* 3) Write I2C address & command to read then receive 3 bytes (2 data + 1 checksum) */
  xI2CTransaction.Operation = I2C_Operation_Read;
  xI2CTransaction.Length    = 3;
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);
  while (SHT2X_I2C_INSTANCE->SR_b.LENGTH < 3)
    ;
  /* Check read */
  do
  {
    if (I2C_OP_ABORTED == I2C_GetStatus(SHT2X_I2C_INSTANCE))
      while (1)
        ;

  } while (RESET == I2C_GetITStatus(SHT2X_I2C_INSTANCE, I2C_IT_MTD));

  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MTD | I2C_IT_MTDWS);
  *puwTemperature =
      (I2C_ReceiveData(SHT2X_I2C_INSTANCE) << 8) | I2C_ReceiveData(SHT2X_I2C_INSTANCE);
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MSK);
}