#pragma once

#include "app_util_platform.h"
#include "battery_sensor_types.h"
#include "opt3001_types.h"
#include "shtc3_types.h"
#include "soilhum_types.h"

/**
 * Stores all sensor measurement results to be transmitted bia BLE
 * Total size: 18 bytes + 2 padding bytes = 20 bytes
 */
typedef struct
{
    uint32_t          unix_epoch_time; // Timestamp of the data
    soilhum_t         soil_humidity;
    luminous_flux_t   lum_flux;
    airhum_t          airhum_phys;
    airtemp_t         airtemp_phys;
    battery_voltage_t battery_mv; // Current battery voltage in millivolts
    uint8_t           padding[2]; // Explicitly defining padding bytes (compiler would add them anyway)
} sensor_data_t;

void sensors_init(void);