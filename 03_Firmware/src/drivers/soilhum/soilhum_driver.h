#pragma once

#include "soilhum_types.h"
#include <stdint.h>

void      drv_soilhum_init();
void      drv_soilhum_meas_start(void);
soilhum_t drv_soilhum_get_frequency(void);