#include "i2c.h"

#include "BlueNRG1_i2c.h"

void i2c_init(void)
{
  I2C_InitType xI2CConfig; // I2C configuration

  /* Enable the I2C Clock */
  SysCtrl_PeripheralClockCmd(SHTC3_I2C_PERIPH_CLK, ENABLE);

  // Disable I2C peripheral
  I2C_Cmd(SHTC3_I2C_INSTANCE, DISABLE);
  /* First configure the appropriate pins in I2C mode */
  SHTC3_Init_SCL();
  SHTC3_Init_SDA();
  // Then inits the I2C peripheral
  I2C_StructInit(&xI2CConfig);
  xI2CConfig.I2C_ClockSpeed    = SHTC3_I2C_CLK_SPEED;
  xI2CConfig.I2C_OperatingMode = I2C_OperatingMode_Master;
  xI2CConfig.I2C_Filtering     = I2C_Filtering_1Ck_Spike;
  I2C_Init(SHTC3_I2C_INSTANCE, &xI2CConfig);
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHTC3_I2C_INSTANCE, I2C_IT_MSK);

  /* Flush TX and RX buffers */
  I2C_FlushRx(SHTC3_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHTC3_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  I2C_FlushTx(SHTC3_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHTC3_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
}

int i2c_write(uint8_t addr, const uint8_t* data, uint8_t len)
{
  I2C_TransactionType t;

  // Write the slave address
  t.Operation     = I2C_Operation_Write;
  t.Address       = addr;
  t.StartByte     = I2C_StartByte_Disable;
  t.AddressType   = I2C_AddressType_7Bit;
  t.StopCondition = I2C_StopCondition_Enable;
  t.Length        = len;

  // Flush the slave address
  I2C_FlushTx(SHTC3_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHTC3_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  // Begin transaction
  I2C_BeginTransaction(SHTC3_I2C_INSTANCE, &t);

  for (uint8_t i = 0; i < len; i++) { I2C_FillTxFIFO(SHTC3_I2C_INSTANCE, data[i]); }

  // Wait loop
  do {
    if (I2C_GetStatus(SHTC3_I2C_INSTANCE) == I2C_OP_ABORTED)
    {
      return ERROR;
    }
  } while (I2C_GetITStatus(SHTC3_I2C_INSTANCE, I2C_IT_MTD) == RESET);

  // Clear pending bits
  I2C_ClearITPendingBit(SHTC3_I2C_INSTANCE, I2C_IT_MTD | I2C_IT_MTDWS);

  return SUCCESS;
}

int i2c_read(uint8_t addr, uint8_t* data, uint8_t len)
{
  I2C_TransactionType t;

  // read data
  t.Operation     = I2C_Operation_Read;
  t.Address       = addr;
  t.StartByte     = I2C_StartByte_Disable;
  t.AddressType   = I2C_AddressType_7Bit;
  t.StopCondition = I2C_StopCondition_Enable;
  t.Length        = len;

  I2C_BeginTransaction(SHTC3_I2C_INSTANCE, &t);

  // Wait loop
  do {
    if (I2C_OP_ABORTED == I2C_GetStatus(SHTC3_I2C_INSTANCE))
    {
      return ERROR;
    }
  } while (RESET == I2C_GetITStatus(SHTC3_I2C_INSTANCE, I2C_IT_MTD));

  // Clear pending bits
  I2C_ClearITPendingBit(SHTC3_I2C_INSTANCE, I2C_IT_MTD | I2C_IT_MTDWS);

  // Get data from RX FIFO
  while (len--)
  {
    *data = I2C_ReceiveData(SHTC3_I2C_INSTANCE);
    data++;
  }

  return SUCCESS;
}

void i2c_write_register(uint8_t addr, uint8_t reg, const uint8_t* data, uint8_t len)
{
  uint8_t buffer[len + 1];
  buffer[0] = reg;
  for (uint8_t i = 0; i < len; i++) { buffer[i + 1] = data[i]; }
  i2c_write(addr, buffer, len + 1);
}

void i2c_read_register(uint8_t addr, uint8_t reg, uint8_t* dest, uint8_t len)
{
  i2c_write(addr, &reg, 1);
  i2c_read(addr, dest, len);
}