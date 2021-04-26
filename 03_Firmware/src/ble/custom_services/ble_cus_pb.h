#pragma once

#include "ble.h"
#include "ble_srv_common.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/**@brief   Macro for defining a ble_hrs instance.
 *
 * @param   _name   Name of the instance.
 * @hideinitializer
 */
// TODO: Make variable static!
#define BLE_CUS_PB_DEF(_name) \
    ble_cus_pb_t _name;       \
    NRF_SDH_BLE_OBSERVER(_name##_obs, BLE_HRS_BLE_OBSERVER_PRIO, ble_cus_pb_on_ble_evt, &_name)

// UUID: f4c2XXXX-6e5f-48a2-b9b2-a4f762791d85
// clang-format off
#define CUSTOM_SERVICE_UUID_BASE                        \
{{                                                      \
    0x85, 0x1D, 0x79, 0x62, 0xF7, 0xA4, 0xB2, 0xB9,     \
    0xA2, 0x48, 0x5F, 0x6E, 0x00, 0x00, 0xC2, 0xF4      \
}}
// clang-format on

#define CUSTOM_SERVICE_UUID   0xABCD
#define SENSOR_DATA_CHAR_UUID 0x0001

/**@brief Custom Service event type. */
typedef enum
{
    BLE_CUS_PB_EVT_NOTIFICATION_ENABLED,  /**< Custom value notification enabled event. */
    BLE_CUS_PB_EVT_NOTIFICATION_DISABLED, /**< Custom value notification disabled event. */
    BLE_CUS_PB_EVT_DISCONNECTED,
    BLE_CUS_PB_EVT_CONNECTED
} ble_cus_pb_evt_type_t;

/**@brief Custom Service event. */
typedef struct
{
    ble_cus_pb_evt_type_t evt_type; /**< Type of event. */
} ble_cus_pb_evt_t;

// Forward declaration of the ble_cus_pb_t type.
typedef struct ble_cus_pb_s ble_cus_pb_t;

/**@brief Custom Service event handler type. */
typedef void (*ble_cus_pb_evt_handler_t)(ble_cus_pb_t* p_bas, ble_cus_pb_evt_t* p_evt);

/**@brief Battery Service init structure. This contains all options and data needed for
 *        initialization of the service.*/
typedef struct
{
    ble_cus_pb_evt_handler_t evt_handler; /**< Event handler to be called for handling events in the Custom Service. */
} ble_cus_pb_init_t;

/**@brief Custom Service structure. This contains various status information for the service. */
struct ble_cus_pb_s
{
    ble_cus_pb_evt_handler_t evt_handler; /**< Event handler to be called for handling events in the Custom Service. */
    uint16_t                 service_handle; /**< Handle of Custom Service (as provided by the BLE stack). */
    uint8_t                  uuid_type;      /**< Service type */
    uint16_t                 conn_handle;    /**< Handle of the current connection (as provided by the BLE stack, is
                                                BLE_CONN_HANDLE_INVALID if not in a connection). */
    ble_gatts_char_handles_t char_lumflux_handle; /**< Handle of the Luminous Flux characteristic. */
    ble_gatts_char_handles_t char_soilhum_handle; /**< Handle of the Soil Humidity characteristic. */
    ble_gatts_char_handles_t char_airtemp_handle; /**< Handle of the Air Temperature characteristic. */
    ble_gatts_char_handles_t char_airhum_handle;  /**< Handle of the Air Humidity characteristic. */
};

/**@brief Function for initializing the Custom Service.
 *
 * @param[out]  p_cus       Custom Service structure. This structure will have to be supplied by
 *                          the application. It will be initialized by this function, and will later
 *                          be used to identify this particular service instance.
 * @param[in]   p_cus_init  Information needed to initialize the service.
 *
 * @return      NRF_SUCCESS on successful initialization of service, otherwise an error code.
 */
uint32_t ble_cus_pb_init(ble_cus_pb_t* p_cus, const ble_cus_pb_init_t* p_cus_init);

/**@brief Function for handling the Application's BLE Stack events.
 *
 * @details Handles all events from the BLE stack of interest to the Battery Service.
 *
 * @note
 *
 * @param[in]   p_cus      Custom Service structure.
 * @param[in]   p_ble_evt  Event received from the BLE stack.
 */
void ble_cus_pb_on_ble_evt(ble_evt_t const* p_ble_evt, void* p_context);