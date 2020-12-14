#ifndef LED_H__
#define LED_H__
#include "BlueNRG1_gpio.h"

#define LED_PIN          GPIO_Pin_4 | GPIO_Pin_3
#define LED_BLINK_PERIOD 500U

void vLEDInit(void);
void vLEDPeriodicTask(void* pvParams);

#endif