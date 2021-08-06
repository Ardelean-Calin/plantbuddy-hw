#include "datalogger.h"
#include <string.h>

void datalogger_init()
{
    memset(sensorDataBuffer, 0, sizeof(sensor_data_t) * LOG_ENTRIES);
    bufferIndex = 0;
}

/**
 * @brief Adds a new entry to the log.
 */
void datalogger_add(sensor_data_t dataEntry)
{
    sensorDataBuffer[bufferIndex] = dataEntry;

    bufferIndex++;
    if (bufferIndex >= LOG_ENTRIES)
    {
        bufferIndex = 0;
    }
}

/**
 * @brief This task is responsible with data logging
 */
// void datalogger_task(void)
