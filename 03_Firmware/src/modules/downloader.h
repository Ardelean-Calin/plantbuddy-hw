#pragma once

#include "sensors.h"

/* ENUMS */
typedef enum packet_type_enum
{
    PACKET_NONE = 0,
    PACKET_INFO = 1,
    PACKET_DATA = 2,
} packet_type_enum_t;

/* I control behavior via the control characteristic and read back responses via the response characteristic */
typedef enum downloader_request_type_enum
{
    REQ_INFO         = 0x00,
    REQ_ABORT        = 0x10,
    REQ_PACKET_BY_ID = 0x11, // Request packet by ID
} downloader_reqtype_t;

typedef enum
{
    TRANSACTION_DONE    = 0,
    TRANSACTION_ONGOING = 1,
};

/* STRUCTS */
/* Params definition */
typedef struct params_data_since_ts_s
{
    uint32_t timestamp;
} params_data_since_ts_t;

/* Definition of a request */
typedef struct downloader_request_s
{
    downloader_reqtype_t type;
    union
    {
        /* Here we can add different parameters which we want to give to our request */
        uint16_t packet_id; // if type == REQ_PACKET_BY_ID
    } params;
} downloader_request_t;

/* Definition of an information packet */
typedef struct downloader_info_s
{
    uint8_t  ongoing;                // Flag indicating wether a transaction is ongoing
    uint8_t  remaining_transactions; // The total number of transactions to be processed
    uint16_t remaining_bytes;        // The total number of bytes to be transferred
} downloader_info_t;

/* Generic packet definition. This will be sent to the characteristic. */
typedef struct downloader_packet_s
{
    union
    {
        sensor_data_t     data;
        downloader_info_t info;
    } packet;
} downloader_packet_t;

void downloader_init(void);