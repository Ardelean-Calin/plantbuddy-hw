#pragma once

#include "ble_cus_pb.h"
#include "downloader.h"
#include <stdint.h>

uint32_t char_downloader_add_to_service(ble_cus_pb_t* p_cus);
uint32_t char_downloader_update(sensor_data_t* new_packet);