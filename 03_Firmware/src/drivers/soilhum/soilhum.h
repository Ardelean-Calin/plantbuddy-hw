#pragma once

#include <stdint.h>

typedef uint32_t soilhum_t;

void      soilhum_init();
void      soilhum_meas_start(void);
soilhum_t soilhum_get_frequency(void);