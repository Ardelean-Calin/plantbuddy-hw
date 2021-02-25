#pragma once

#include "soilhum_types.h"
#include <stdint.h>

void drv_soilhum_init(soilhum_t* freq);
void drv_soilhum_meas_start(void);