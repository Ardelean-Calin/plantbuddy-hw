#pragma once

#include "app_util.h"
#include "sensors.h"

#define LOG_ENTRIES  100                                    // The total number of log entries
#define LOG_SIZE     (LOG_ENTRIES * sizeof(sensor_data_t))  // Size of the log buffer in RAM
#define LOG_MEMORY_S 604                                    // Logs are kept in memory this amount of time (7d)
#define LOG_PERIOD_S ROUNDED_DIV(LOG_MEMORY_S, LOG_ENTRIES) // Every this amount of seconds we save to log

enum DATALOGGER_ERRORS
{
    LOGGER_NO_ERROR     = 0,
    LOGGER_ID_TOO_BIG   = 1,
    LOGGER_ID_TOO_SMALL = 2,
};

void    datalogger_init(void);
void    datalogger_task(void);
uint8_t datalogger_get_by_id(uint16_t packet_id, sensor_data_t* p_data);
void    datalogger_get_minmax_id(uint16_t* p_min, uint16_t* p_max);