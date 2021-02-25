#pragma once

#include "ble_cus_pb.h"
#include "soilhum_types.h"
#include <stdint.h>

uint32_t char_soilhum_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_soilhum_update(ble_cus_pb_t* p_cus, soilhum_t new_soilhum);