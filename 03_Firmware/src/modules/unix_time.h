#pragma once
#include "compiler_abstraction.h"
#include "nordic_common.h"
#include "nrf.h"
#include <stddef.h>
#include <stdint.h>

typedef uint32_t unix_time_t;

void        unix_time_init(void);
unix_time_t unix_time_get_timestamp();
void        unix_time_update_timestamp(unix_time_t timestamp);
