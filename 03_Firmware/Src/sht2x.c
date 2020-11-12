#include "sht2x.h"
#include "BlueNRG1_i2c.h"
#include "FreeRTOS.h"
#include "task.h"
#include "UserConfig.h"

/* Function prototypes */
static void vTransmitCmd(uint8_t ucCommand);
static void vReadData(uint8_t* pucDestBuf, uint8_t ucLength);
static void vRequestData(uint8_t ucReg, uint8_t ucLength, uint8_t* pucDestBuf, uint8_t ucDelay);

static I2C_TransactionType xI2CTransaction;

uint16_t uwSHT2XRawTemp;
uint16_t uwSHT2XRawRH;

/**
 * @brief Initialises this module.
 */
void vSHT2XInit(void)
{ /* Initializes this module */
  xI2CTransaction.Address       = SHT2X_I2C_ADDRESS;
  xI2CTransaction.Operation     = I2C_Operation_Write;
  xI2CTransaction.AddressType   = I2C_AddressType_7Bit;
  xI2CTransaction.StartByte     = I2C_StartByte_Disable;
  xI2CTransaction.StopCondition = I2C_StopCondition_Enable;
  xI2CTransaction.Length        = 1;

  uwSHT2XRawTemp = 0;
  uwSHT2XRawRH   = 0;

  /* Flush TX and RX buffers */
  I2C_FlushRx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  I2C_FlushTx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  /* Reset the SHT2X */
  vTransmitCmd(SHT2X_CMD_RESET);
}

/**
 * @brief The periodic task that gathers temperature & relative humidity data from the sensor.
 */
void vSHT2XPeriodicTask(void* pvParameters)
{
  TickType_t       xLastWakeTime;
  const TickType_t xFrequency = pdMS_TO_TICKS(SHT2X_READ_PERIOD);

  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    /* Run periodically */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    // Request temperature data
    vRequestData(SHT2X_CMD_READ_TEMP_NOHOLD,
                 SHT2X_I2C_DATASIZE,
                 (uint8_t*)(&uwSHT2XRawTemp),
                 SHT2X_TEMP_14BIT_DELAY);
    // Request humidity data
    vRequestData(SHT2X_CMD_READ_RH_NOHOLD,
                 SHT2X_I2C_DATASIZE,
                 (uint8_t*)&uwSHT2XRawRH,
                 SHT2X_RH_14BIT_DELAY);
  }
}

/**
 * @brief Transmits a command to the SHT2X. Command can be: Read T/RH, Reset, Write User Register
 */
static void vTransmitCmd(uint8_t ucCommand)
{
  xI2CTransaction.Operation = I2C_Operation_Write;
  xI2CTransaction.Length    = 1;
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);
  I2C_FillTxFIFO(SHT2X_I2C_INSTANCE, ucCommand);
  while (I2C_GetStatus(SHT2X_I2C_INSTANCE) != I2C_OP_OK)
    ; // Wait for Tx
}

/**
 * @brief Reads a certain number of bytes from the I2C bus
 */
static void vReadData(uint8_t* pucDestBuf, uint8_t ucLength)
{
  uint8_t i;

  xI2CTransaction.Operation = I2C_Operation_Read;
  xI2CTransaction.Length    = ucLength;
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);
  while (SHT2X_I2C_INSTANCE->SR_b.LENGTH < ucLength)
    ; // Wait for Rx

  // Read the received bytes into an array.
  // NOTE: I am ignoring checksum for now, might be useful to implement later
  i = ucLength;
  do
  {
    i--;
    *(pucDestBuf + i) = I2C_ReceiveData(SHT2X_I2C_INSTANCE);
  } while (i > 0);
}

/**
 * @brief Requests either temperature or humidity data (specified via the ucCommand parameter)
 */
static void vRequestData(uint8_t ucCommand, uint8_t ucLength, uint8_t* pucDestBuf, uint8_t ucDelay)
{
  /* Request some data after issuing a command */
  vTransmitCmd(ucCommand);
  vTaskDelay(pdMS_TO_TICKS(ucDelay));
  vReadData(pucDestBuf, ucLength);
  /* Clear RX buffer */
  I2C_FlushRx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MSK);
}