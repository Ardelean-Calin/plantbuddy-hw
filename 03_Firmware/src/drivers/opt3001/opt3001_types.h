#pragma once

typedef union
{
    struct
    {
        uint32_t address : 8;
        uint32_t config : 16;
    };
    uint8_t raw[4];
} opt3001_packet_t;

// The luminous flux will be encoded in this variable.
typedef uint32_t luminous_flux_t;