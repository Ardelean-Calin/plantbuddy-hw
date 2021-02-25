#pragma once

#include "ble_cus_pb.h"
#include "shtc3_types.h"
#include <stdint.h>

uint32_t char_airhum_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_airhum_update(ble_cus_pb_t* p_cus, airhum_t new_airhum);