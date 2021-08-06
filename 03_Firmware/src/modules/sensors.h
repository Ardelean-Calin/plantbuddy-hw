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
    unix_time_t       unix_epoch_time; // 4 bytes
    soilhum_t         soil_humidity;   // 4 bytes
    luminous_flux_t   lum_flux;        // 4 bytes
    airhum_t          airhum_phys;     // 2 bytes
    airtemp_t         airtemp_phys;    // 2 bytes
    battery_voltage_t battery_mv;      // 2 bytes
} sensor_data_t;                       // Total: 18 bytes

void sensors_init(void);
void sensors_task(void);
void sensors_get_latest(sensor_data_t* p_dest);