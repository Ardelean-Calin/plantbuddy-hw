#pragma once
#include "battery_sensor_types.h"
#include <stdint.h>

#define BATT_SENSOR_CFG_RES     1024
#define BATT_SENSOR_CFG_VMAX_MV 600
#define BATT_SENSOR_CFG_GAIN    6

// Max range: 0-3.3V
#define BATT_SENSOR_RAW_TO_PHYS(raw_val) \
    ((uint32_t)(raw_val * BATT_SENSOR_CFG_VMAX_MV * BATT_SENSOR_CFG_GAIN) / BATT_SENSOR_CFG_RES)

#define SAADC_SAMPLES_IN_BUFFER 1

void              batt_sensor_init(void);
void              batt_sensor_meas_start(void);
battery_voltage_t batt_sensor_get_voltage(void);