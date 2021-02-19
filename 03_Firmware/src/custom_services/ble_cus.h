#pragma once

#include "ble.h"
#include "ble_srv_common.h"
#include <stdbool.h>
#include <stdint.h>

// clang-format off
// UUID: bcc6da74-3434-4a75-b374-45de98dc83ae
#define PB_SERVICE_UUID_BASE {0xAE, 0x83, 0xDC, 0x98, 0xDE, 0x45, 0x74, 0xB3, \
                              0x75, 0x4A, 0x34, 0x34, 0x74, 0xDA, 0xC6, 0xBC}
// clang-format on

#define PB_SERVICE_UUID    0x1400
#define PB_LUX_CHAR_UUID   0x1401
#define PB_TEMP_CHAR_UUID  0x1402
#define PB_HUM_CHAR_UUID   0x1403
#define PB_SOILH_CHAR_UUID 0x1404

/**
 * @brief   Macro for defining a ble_cus instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
#define BLE_CUS_DEF(_name) static ble_cus_t _name;

/**
 * @brief Custom Service init structure. This contains all options and data needed for
 *        initialization of the service.
 */
typedef struct
{
    uint8_t initial_custom_value; /**< Initial custom value */
    ble_srv_cccd_security_mode_t
        custom_value_char_attr_md; /**< Initial security level for Custom characteristics attribute */
} ble_cus_init_t;

/**
 * @brief Custom Service structure. This contains various status information for the service.
 */
struct ble_cus_s
{
    uint16_t                 service_handle;       /**< Handle of Custom Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t custom_value_handles; /**< Handles related to the Custom Value characteristic. */
    uint16_t                 conn_handle; /**< Handle of the current connection (as provided by the BLE stack, is
                                             BLE_CONN_HANDLE_INVALID if not in a connection). */
    uint8_t uuid_type;
};
// Forward declaration of the ble_cus_t type.
typedef struct ble_cus_s ble_cus_t;

/* This code belongs in ble_cus.c*/

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_cus       Custom Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_cus_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_cus_init(ble_cus_t* p_cus, const ble_cus_init_t* p_cus_init);