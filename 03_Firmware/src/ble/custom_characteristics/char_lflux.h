#pragma once

#include "ble_cus.h"
#include <stdint.h>

uint32_t char_lflux_add_to_service(ble_cus_t* p_cus, const ble_cus_init_t* p_cus_init);
uint32_t char_lflux_update(ble_cus_t* p_cus, uint32_t new_lflux);