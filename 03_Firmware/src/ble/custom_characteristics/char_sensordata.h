#pragma once

#include "ble_cus_pb.h"
#include "sensors.h"
#include <stdint.h>

uint32_t char_sensordata_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_sensordata_update(sensor_data_t new_sensor_data);