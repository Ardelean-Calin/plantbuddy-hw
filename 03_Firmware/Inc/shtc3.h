#ifndef SHTC3_H__
#define SHTC3_H__

#define SHTC3_I2C_ADDRESS 0x70 // The I2C Address of an SHTC3

#define SHTC3_I2C_TXPACKET_LEN 2U
#define SHTC3_I2C_RXPACKET_LEN 6U

#define SHTC3_TASK_PERIOD 1000 // Read new temperature and humidity data every X period

/* The acceptable states of the state machine */
typedef enum
{
  SHTC3_STATE_INIT = 0,
  SHTC3_STATE_WAKEUP,
  SHTC3_STATE_MEAS_START,
  SHTC3_STATE_MEAS_READ,
  SHTC3_STATE_MEAS_SLEEP
} eSHTC3State;

/* Initialization code */
void vSHTC3Init(void);

#endif