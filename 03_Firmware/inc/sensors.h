#pragma once

#include "app_util_platform.h"
#include "battery_sensor.h"
#include "opt3001_types.h"
#include "shtc3_types.h"
#include "soilhum_types.h"

/* Stores all sensor measurement results to be transmitted bia BLE */
typedef struct
{
    soilhum_t       soil_humidity;
    luminous_flux_t lum_flux;
    airhum_t        airhum_raw;
    airtemp_t       airtemp_raw;
} sensor_data_t;

void sensors_init(void);