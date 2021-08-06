#pragma once

#include "app_util.h"
#include "sensors.h"

#define LOG_ENTRIES   100                                           // The total number of log entries
#define LOG_SIZE      (LOG_ENTRIES * sizeof(sensor_data_t))         // Size of the log buffer in RAM
#define LOG_MEMORY_S  604800                                        // Logs are kept in memory this amount of time (7d)
#define LOG_PERIOD_MS ROUNDED_DIV(1000 * LOG_MEMORY_S, LOG_ENTRIES) // Every this amount of ms we save to log

sensor_data_t sensorDataBuffer[LOG_ENTRIES]; // Buffer which will contain our logs
uint16_t      bufferIndex;

void datalogger_init(void);