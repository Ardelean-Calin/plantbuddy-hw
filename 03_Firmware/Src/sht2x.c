#include "sht2x.h"
#include "BlueNRG1_i2c.h"
#include "FreeRTOS.h"
#include "task.h"

/* Static Function prototypes */
static void    vI2CReInit(void);
static uint8_t vSHT2XSetResolution(void);
static void
vSHT2XPeriodicTask(void* pvParameters); /* Retreives the current temperature and humidity */

/* Public Function prototypes => to be moved */
int i2c_write(uint8_t addr, uint8_t* data, uint8_t len);
int i2c_read(uint8_t addr, uint8_t* data, uint8_t len);

/* Variables used by this module */
uint16_t       uwSHT2XTemp;
uint16_t       uwSHT2XRH;
static uint8_t pucRawData[6];

/**
 * @brief Initialises this module.
 */
void vSHT2XInit(void)
{
  uwSHT2XTemp = 0;
  uwSHT2XRH   = 0;

  vI2CReInit();

  /* Create our FreeRTOS tasks */
  xTaskCreate(vSHT2XPeriodicTask, "SHT2x", 64, NULL, tskIDLE_PRIORITY + 1U, NULL);
}

static void vI2CReInit(void)
{
  I2C_InitType xI2CConfig; // I2C configuration

  /* Enable the I2C Clock */
  SysCtrl_PeripheralClockCmd(SHT2X_I2C_PERIPH_CLK, ENABLE);

  // Disable I2C peripheral
  I2C_Cmd(SHT2X_I2C_INSTANCE, DISABLE);
  /* First configure the appropriate pins in I2C mode */
  SHT2X_Init_SCL();
  SHT2X_Init_SDA();
  // Then inits the I2C peripheral
  I2C_StructInit(&xI2CConfig);
  xI2CConfig.I2C_ClockSpeed    = SHT2X_I2C_CLK_SPEED;
  xI2CConfig.I2C_OperatingMode = I2C_OperatingMode_Master;
  xI2CConfig.I2C_Filtering     = I2C_Filtering_1Ck_Spike;
  I2C_Init(SHT2X_I2C_INSTANCE, &xI2CConfig);
  // Clear all I2c pending interrupts
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MSK);

  /* Flush TX and RX buffers */
  I2C_FlushRx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushRx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  I2C_FlushTx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;
}

// static uint8_t vSHT2XSetResolution(void)
// {
//   uint8_t ucUserReg;
//   // Read the current value of the user register
//   i2c_read(SHT2X_I2C_ADDRESS, SHT2X_CMD_READ_USER_REG, &ucUserReg, 1);
//   // Rewrite the bits of interest for us
//   ucUserReg &= SHT21_MASK_USER_PROTECTED;
//   ucUserReg |= SHT21_USER_RES_RH8T12;
//   // Then send the data on our way
//   i2c_write(SHT2X_I2C_ADDRESS, SHT2X_CMD_WRITE_USER_REG, &ucUserReg, 1);
// }

/**
 * @brief The periodic task that gathers temperature & relative humidity data from the sensor.
 */
static void vSHT2XPeriodicTask(void* pvParameters)
{
  TickType_t       xLastWakeTime;
  const TickType_t xFrequency = pdMS_TO_TICKS(SHT2X_TASK_PERIOD);
  xLastWakeTime               = xTaskGetTickCount();

  // /* Reset the SHT2X */
  // i2c_write(SHT2X_I2C_ADDRESS, SHT2X_CMD_RESET, NULL, 0);
  // /* Wait at least 15ms for the reset to be complete  */
  // vTaskDelay(pdMS_TO_TICKS(100));
  // /* Then configure the SHT2X to function in low-res mode */
  // vSHT2XSetResolution();

  for (;;)
  {
    /* Run periodically */
    vTaskDelayUntil(&xLastWakeTime, xFrequency);

    // 1. Wakeup
    i2c_write(SHT2X_I2C_ADDRESS, (uint8_t*)&(uint16_t){SHT2X_CMD_WAKEUP}, 2);
    // Chip wakes up in around 240us => 1 tick delay should suffice
    vTaskDelay(1);
    // 2. Start measurement
    i2c_write(SHT2X_I2C_ADDRESS, (uint8_t*)&(uint16_t){SHT2X_CMD_START_MEAS_CSEN}, 2);
    /* Dumb time delay => could poll instead but this may be better for power consumption
     * The measurement should be done in max 12.1 ms in normal mode and 0.9 ms in low-power mode
     */
    vTaskDelay(pdMS_TO_TICKS(20));
    // 3. Read temperature (2 bytes + CRC) & humidity (2 bytes + CRC)
    i2c_read(SHT2X_I2C_ADDRESS, &pucRawData[0], 6);
    // 4. Go to sleep
    i2c_write(SHT2X_I2C_ADDRESS, (uint8_t*)&(uint16_t){SHT2X_CMD_SLEEP}, 2);

    /* Extract the raw temperature and humidity values => to be converted to phys by mobile phone */
    uwSHT2XTemp = (pucRawData[0] << 8) + pucRawData[1];
    uwSHT2XRH   = (pucRawData[3] << 8) + pucRawData[4];
  }
}

int i2c_write(uint8_t addr, uint8_t* data, uint8_t len)
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
  I2C_FlushTx(SHT2X_I2C_INSTANCE);
  while (I2C_WaitFlushTx(SHT2X_I2C_INSTANCE) == I2C_OP_ONGOING)
    ;

  // Begin transaction
  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &t);

  for (uint8_t i = 0; i < len; i++) { I2C_FillTxFIFO(SHT2X_I2C_INSTANCE, data[i]); }

  // Wait loop
  do {
    if (I2C_GetStatus(SHT2X_I2C_INSTANCE) == I2C_OP_ABORTED)
    {
      return ERROR;
    }
  } while (I2C_GetITStatus(SHT2X_I2C_INSTANCE, I2C_IT_MTD) == RESET);

  // Clear pending bits
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MTD | I2C_IT_MTDWS);

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

  I2C_BeginTransaction(SHT2X_I2C_INSTANCE, &t);

  // Wait loop
  do {
    if (I2C_OP_ABORTED == I2C_GetStatus(SHT2X_I2C_INSTANCE))
    {
      return ERROR;
    }
  } while (RESET == I2C_GetITStatus(SHT2X_I2C_INSTANCE, I2C_IT_MTD));

  // Clear pending bits
  I2C_ClearITPendingBit(SHT2X_I2C_INSTANCE, I2C_IT_MTD | I2C_IT_MTDWS);

  // Get data from RX FIFO
  while (len--)
  {
    *data = I2C_ReceiveData(SHT2X_I2C_INSTANCE);
    data++;
  }

  return SUCCESS;
}