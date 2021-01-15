#ifndef __MAIN_H
#define __MAIN_H
/* Public typedefs -----------------------------------------------------------*/
/* Public defines ------------------------------------------------------------*/
#define MAX(a, b)                  ((a >= b) ? a : b)
#define pdMINIMUM_DELAY(xTimeInMs) (MAX(pdMS_TO_TICKS(xTimeInMs), 1U))
/* Public macros -------------------------------------------------------------*/
/* Public variables ---------------------------------------------------------*/
/* Public functions ---------------------------------------------------------*/

#endif