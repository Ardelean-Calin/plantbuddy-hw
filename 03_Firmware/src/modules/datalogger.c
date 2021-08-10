#include "datalogger.h"
#include "sensors.h"
#include <string.h>

uint16_t packet_id; // overflows every 11 years => not happening during a 1 year battery
uint16_t min_packet_id;
uint16_t max_packet_id;
uint32_t invocation_number;

sensor_data_t sensorDataBuffer[LOG_ENTRIES]; // Buffer which will contain our logs
uint16_t      bufferIndex;

static void datalogger_add(sensor_data_t dataEntry);

void datalogger_init()
{
    memset(sensorDataBuffer, 0, sizeof(sensor_data_t) * LOG_ENTRIES);
    bufferIndex       = 0;
    invocation_number = 0;
    packet_id         = 0;
    max_packet_id     = 0;
    min_packet_id     = 0;
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

/**
 * @brief Adds a new entry to the log. Rolling buffer.
 */
static void datalogger_add(sensor_data_t dataEntry)
{
    dataEntry.packet_id           = max_packet_id++;
    sensorDataBuffer[bufferIndex] = dataEntry;

    // Increment the minimum packet id if we overran
    if (max_packet_id - min_packet_id >= LOG_ENTRIES)
    {
        min_packet_id++;
    }

    // Circular buffer implementation
    bufferIndex++;
    if (bufferIndex >= LOG_ENTRIES)
    {
        bufferIndex = 0;
    }
}

/**
 * @brief Fetches the corresponding sensor data. ID's are always ascending
 */
uint8_t datalogger_get_by_id(uint16_t packet_id, sensor_data_t* p_data)
{
    uint8_t error = LOGGER_NO_ERROR;

    if (packet_id > max_packet_id)
    { // Impossible request, this packet was not generated yet!
        error = LOGGER_ID_TOO_BIG;
    }
    else if (packet_id < MIN(0, max_packet_id - LOG_ENTRIES))
    {
        error = LOGGER_ID_TOO_SMALL;
    }
    else
    {
        // Packet ID between min and max
        sensor_data_t temp_data;
        // Find the given packet ID
        for (uint16_t i = 0; i < LOG_ENTRIES; i++)
        {
            temp_data = sensorDataBuffer[i];
            if (temp_data.packet_id == packet_id)
            {
                p_data = &temp_data;
            }
        }
    }

    return error;
}

void datalogger_get_minmax_id(uint16_t* p_min, uint16_t* p_max)
{
    *p_min = min_packet_id;
    *p_max = max_packet_id - 1;
}