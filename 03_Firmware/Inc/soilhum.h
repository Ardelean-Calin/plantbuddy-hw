#ifndef SOILH_H__
#define SOILH_H__
#include "BlueNRG1_gpio.h"

#define SOILHUM_PIN_IN     GPIO_Pin_11
#define SOILHUM_PIN_IN_POS (11) // Since this is GPIO11 => pos is 11
#define SOILHUM_PIN_ENABLE GPIO_Pin_6

#define SOILHUM_TASK_PERIOD 1000 // Update soil humidity measurement every 1000ms

/* Public function defines */
void vSoilHumInit(void);
void vSoilHumPeriodicTask(void* pvParams);
void vSoilHumTimerInterrupt(void* pvParams);

#endif