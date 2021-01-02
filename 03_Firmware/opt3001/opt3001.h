#ifndef OPT3001_H__
#define OPT3001_H__

#define OPT_I2C_ADDRESS       0x44
#define OPT_TASK_PERIOD       1000 // task period in ms ! SHOULD NOT BE LOWER THAN 900ms
#define OPT3001_PIN_INTERRUPT GPIO_Pin_8

/* The acceptable states of the state machine */
typedef enum
{
  OPT_STATE_INIT = 0,
  OPT_STATE_CONFIGURE,
  OPT_STATE_START_CONVERSION,
  OPT_STATE_ONGOING,
  OPT_STATE_RESULT,
} eOPT3001State;

void vOPT3001Init(void);

#endif