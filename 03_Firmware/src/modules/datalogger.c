#include "datalogger.h"
#include "sensors.h"
#include <string.h>

uint32_t invocation_number;

void datalogger_init()
{
    memset(sensorDataBuffer, 0, sizeof(sensor_data_t) * LOG_ENTRIES);
    bufferIndex       = 0;
    invocation_number = 0;
}

/**
 * @brief Adds a new entry to the log. Rolling buffer.
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
 * @brief This task is responsible with data logging. It is run every second.
 */
void datalogger_task(void)
{
    sensor_data_t latest_sensor_data;

    if (invocation_number % LOG_PERIOD_S == 0)
    {
        /* Get the latest sensor data */
        sensors_get_latest(&latest_sensor_data);

        /* Now add said data to log */
        datalogger_add(latest_sensor_data);
    }

    /* Incremented every time this task is ran */
    invocation_number++;
}
