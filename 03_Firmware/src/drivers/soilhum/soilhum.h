#pragma once

#include "pb_config.h"
#include <stdint.h>

#define SOILHUM_MEAS_PERIOD_MS SENSORS_MEAS_PERIOD_MS

typedef uint32_t soilhum_t;

typedef enum SoilHum_State
{
    SoilHum_SM_IDLE = 0,
    SoilHum_SM_MEASURE,
} eSoilHum_State;

void      soilhum_init();
void      soilhum_sm_tick(void);
soilhum_t soilhum_get_frequency(void);