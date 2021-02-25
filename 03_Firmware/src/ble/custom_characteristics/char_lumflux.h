#pragma once

#include "ble_cus_pb.h"
#include "opt3001_types.h"
#include <stdint.h>

uint32_t char_lumflux_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_lumflux_update(ble_cus_pb_t* p_cus, luminous_flux_t new_lflux);