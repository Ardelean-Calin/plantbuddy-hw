#pragma once

#include "app_util_platform.h"
#include "battery_sensor.h"
#include "opt3001_types.h"
#include "shtc3_types.h"
#include "soilhum_types.h"

/* Stores all sensor measurement results to be transmitted bia BLE */
typedef struct
{
    uint32_t        unix_epoch_time; // Timestamp of the data
    soilhum_t       soil_humidity;
    luminous_flux_t lum_flux;
    airhum_t        airhum_phys;
    airtemp_t       airtemp_phys;
} sensor_data_t;

void sensors_init(void);