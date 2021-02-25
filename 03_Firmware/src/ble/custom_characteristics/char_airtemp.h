#pragma once

#include "ble_cus_pb.h"
#include "shtc3_types.h"
#include <stdint.h>

uint32_t char_airtemp_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_airtemp_update(ble_cus_pb_t* p_cus, airtemp_t new_airtemp);