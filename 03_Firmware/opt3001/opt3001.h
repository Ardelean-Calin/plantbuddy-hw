#ifndef OPT3001_H__
#define OPT3001_H__

#define OPT_I2C_ADDRESS       0x44
#define OPT_TASK_PERIOD       10000 // task period in ms
#define OPT3001_PIN_INTERRUPT GPIO_Pin_8

/* The acceptable states of the state machine */
typedef enum
{
  OPT_STATE_INIT = 0,
  OPT_STATE_ACTIVE,
  OPT_STATE_READ,
  OPT_STATE_SLEEP,
  OPT_STATE_WAIT // Wait for the next invocation of the periodic task
} eOPT3001State;

void vOPT3001Init(void);

#endif