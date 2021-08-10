#include "downloader.h"
#include "app_error.h"
#include "char_downloader.h"
#include "datalogger.h"
#include "sensors.h"
#include <string.h>

uint32_t current_timestamp;
uint32_t next_timestamp;

downloader_packet_t current_packet;
enum current_state_enum
{
    STATE_READY = 0,
    STATE_ONGOING
} current_state;

/**
 * @brief Initializes the data download module.
 */
void downloader_init(void)
{
    current_state = STATE_READY;

    memset((void*)&current_packet, 0U, sizeof(downloader_packet_t));
}

void downloader_process_request(downloader_request_t request)
{
    downloader_reqtype_t req_type = request.type;

    switch (req_type)
    {
    case REQ_INFO:
        /* code */
        break;

    case REQ_PACKET_BY_ID:
        sensor_data_t* p_data;

        uint16_t packet_id = request.params.packet_id;
        uint8_t  error     = datalogger_get_by_id(packet_id, p_data);

        if (error != LOGGER_NO_ERROR)
        {
            // Error! We requested a too big ID or a too small ID => return the max/min allowed values
        }
        else
        {
            current_packet.packet.data = *p_data;
            // Update characteristic value
            char_downloader_update(&current_packet);
        }
        break;
    case REQ_ABORT: // Dunno what to do here, yet...
    default:
        break;
    }
}

void downloader_get_length();
void downloader_set_pointer();