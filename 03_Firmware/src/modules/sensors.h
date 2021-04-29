#pragma once

#include "app_util_platform.h"
#include "battery_sensor_types.h"
#include "opt3001_types.h"
#include "shtc3_types.h"
#include "soilhum_types.h"
#include "unix_time.h"

/**
 * Stores all sensor measurement results to be transmitted bia BLE
 * Total size: 20 bytes => Will be a multiple of 4 unless PACKED is specified
 */
typedef struct
{
    unix_time_t       unix_epoch_time; // Timestamp of the data
    soilhum_t         soil_humidity;
    luminous_flux_t   lum_flux;
    airhum_t          airhum_phys;
    airtemp_t         airtemp_phys;
    battery_voltage_t battery_mv; // Current battery voltage in millivolts
} sensor_data_t;

void sensors_init(void);