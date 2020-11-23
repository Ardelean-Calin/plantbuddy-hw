#include "sht2x.h"
#include "BlueNRG1_i2c.h"
#include "FreeRTOS.h"
#include "task.h"

/* Function prototypes */
static void vI2CReInit(void);
static void vSHT2XWriteRegister(uint8_t ucRegister, uint8_t ucLength, uint8_t* pucTxBuffer);
static void vSHT2XReadRegister(uint8_t ucRegister, uint8_t ucLength, uint8_t* pucRxBuffer,
                               uint8_t ucDelay);

static I2C_TransactionType xI2CTransaction;

uint16_t uwSHT2XRawTemp;
uint16_t uwSHT2XRawRH;
uint8_t  ucUserReg;

/**
 * @brief Initialises this module.
 */
void vSHT2XInit(void)
{
  uwSHT2XRawTemp = 0;
  uwSHT2XRawRH   = 0;
  ucUserReg      = 0;

  vI2CReInit();

  /* Create our FreeRTOS tasks */
  xTaskCreate(vSHT2XPeriodicTask, "SHT2x", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
}

static void vI2CReInit(void)
{
  /* First configure the appropriate pins in I2C mode */
  I2C_InitType xI2CConfig; // I2C configuration
  /* Enable the I2C Clock */
  SysCtrl_PeripheralClockCmd(SHT2X_I2C_PERIPH_CLK, ENABLE);

  // Disable I2C peripheral
  I2C_Cmd(SHT2X_I2C_INSTANCE, DISABLE);

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

  /* The properly initialize this module */
  xI2CTransaction.Address       = SHT2X_I2C_ADDRESS;
  xI2CTransaction.Operation     = I2C_Operation_Write;
  xI2CTransaction.AddressType   = I2C_AddressType_7Bit;
  xI2CTransaction.StartByte     = I2C_StartByte_Disable;
  xI2CTransaction.StopCondition = I2C_StopCondition_Enable;
  xI2CTransaction.Length        = 1;

  /* Flush TX and RX buffers */
  I2C_FlushRx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  I2C_FlushTx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
}

/**
 * @brief The periodic task that gathers temperature & relative humidity data from the sensor.
 */
void vSHT2XPeriodicTask(void* pvParameters)
{
  TickType_t       xLastWakeTime;
  const TickType_t xFrequency = pdMS_TO_TICKS(I2C_Operation_Read_PERIOD);
  xLastWakeTime               = xTaskGetTickCount();

  /* Reset the SHT2X */
  vSHT2XWriteRegister(SHT2X_CMD_RESET, 0, NULL);
  /* Wait 20ms for the reset to be complete  */
  vTaskDelay(pdMS_TO_TICKS(20));

  for (;;)
  {
    /* Run periodically */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);
    // Request temperature data
    vSHT2XReadRegister(SHT2X_CMD_READ_TEMP_NOHOLD,
                       SHT2X_I2C_DATASIZE,
                       (uint8_t*)(&uwSHT2XRawTemp),
                       SHT2X_TEMP_14BIT_DELAY);
    // Request humidity data
    vSHT2XReadRegister(SHT2X_CMD_READ_RH_NOHOLD,
                       SHT2X_I2C_DATASIZE,
                       (uint8_t*)&uwSHT2XRawRH,
                       SHT2X_RH_14BIT_DELAY);
  }
}

static void vSHT2XWriteRegister(uint8_t ucRegister, uint8_t ucLength, uint8_t* pucTxBuffer)
{
  // Write request to given register
  xI2CTransaction.Operation = I2C_Operation_Write;
  xI2CTransaction.Length    = ucLength + 1;
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);
  // The register address
  I2C_FillTxFIFO(SHT2X_I2C_INSTANCE, ucRegister);
  // Now the data bytes
  for (uint8_t i = 0; i < ucLength; i++) { I2C_FillTxFIFO(SHT2X_I2C_INSTANCE, pucTxBuffer[i]); }

  // Wait for transaction to be complete
  while (I2C_GetStatus(SHT2X_I2C_INSTANCE) != I2C_OP_OK)
    ; // Wait for Tx
}

static void vSHT2XReadRegister(uint8_t ucRegister, uint8_t ucLength, uint8_t* pucRxBuffer,
                               uint8_t ucDelay)
{
  uint8_t ucIndex;

  // Start measurement
  vSHT2XWriteRegister(ucRegister, 0, NULL);
  vTaskDelay(pdMS_TO_TICKS(ucDelay));
  // Read request to given register
  xI2CTransaction.Operation = I2C_Operation_Read;
  xI2CTransaction.Length    = ucLength;
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &xI2CTransaction);

  while (SHT2X_I2C_INSTANCE->SR_b.LENGTH < ucLength)
    ; // Wait for Rx

  // Read the received bytes into an array.
  // NOTE: I am ignoring checksum for now, might be useful to implement later
  ucIndex = ucLength;
  do
  {
    ucIndex--;
    *(pucRxBuffer + ucIndex) = I2C_ReceiveData(SHT2X_I2C_INSTANCE);
  } while (ucIndex > 0);

  /* Clear RX buffer */
  I2C_FlushRx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
  I2C_FlushTx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MSK);
}