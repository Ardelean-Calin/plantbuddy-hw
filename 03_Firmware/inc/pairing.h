#pragma once
#include <stdint.h>

/* Main documentation: 99_Documentation/BLE_Pairing_using_NFC.pdf */

typedef struct
{
    uint16_t dataLength; // The total length including the OOB Data Length,  the Bluetooth Device Address, and the OOB
                         // Optional Datafields (see section 3.1.1).
    uint8_t[6] bleDeviceAddr;   // Bluetooth Device Address of the device (see Section 3.1.2) => Little endian
    uint8_t[8] optionalOOBData; // The remaining optional OOB data, in EIR format (seeSection 3.2)
} ble_ssp_oob_data_t;