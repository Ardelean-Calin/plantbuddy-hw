#include "ble_srv_common.h"
#include "nrf_error.h"
#include "sdk_common.h"
#include <string.h>

#include "ble_cus_pb.h"
#include "char_pb_sensors.h"

/**@brief Function for handling the Connect event.
 *
 * @param[in]   p_cus       Custom Service structure.
 * @param[in]   p_ble_evt   Event received from the BLE stack.
 */
static void on_connect(ble_cus_pb_t* p_cus, ble_evt_t const* p_ble_evt)
{
    p_cus->conn_handle = p_ble_evt->evt.gap_evt.conn_handle;

    ble_cus_pb_evt_t evt;

    evt.evt_type = BLE_CUS_PB_EVT_CONNECTED;

    p_cus->evt_handler(p_cus, &evt);
}

/**@brief Function for handling the Disconnect event.
 *
 * @param[in]   p_cus       Custom Service structure.
 * @param[in]   p_ble_evt   Event received from the BLE stack.
 */
static void on_disconnect(ble_cus_pb_t* p_cus, ble_evt_t const* p_ble_evt)
{
    UNUSED_PARAMETER(p_ble_evt);
    p_cus->conn_handle = BLE_CONN_HANDLE_INVALID;

    ble_cus_pb_evt_t evt;

    evt.evt_type = BLE_CUS_PB_EVT_DISCONNECTED;

    p_cus->evt_handler(p_cus, &evt);
}

/**@brief Function for handling the Write event.
 *
 * @param[in]   p_cus       Custom Service structure.
 * @param[in]   p_ble_evt   Event received from the BLE stack.
 */
static void on_write(ble_cus_pb_t* p_cus, ble_evt_t const* p_ble_evt)
{
    ble_gatts_evt_write_t const* p_evt_write = &p_ble_evt->evt.gatts_evt.params.write;

    // Custom Value Characteristic Written to.
    if (p_evt_write->handle == p_cus->char_lumflux_handle.value_handle)
    {
        // Do nothing
    }

    // Check if the Custom value CCCD is written to and that the value is the appropriate length, i.e 2 bytes.
    // if ((p_evt_write->handle == p_cus->char_lumflux_handle.cccd_handle) && (p_evt_write->len == 2))
    // {
    //     // CCCD written, call application event handler
    //     if (p_cus->evt_handler != NULL)
    //     {
    //         ble_cus_pb_evt_t evt;

    //         if (ble_srv_is_notification_enabled(p_evt_write->data))
    //         {
    //             evt.evt_type = BLE_CUS_PB_EVT_NOTIFICATION_ENABLED;
    //         }
    //         else
    //         {
    //             evt.evt_type = BLE_CUS_PB_EVT_NOTIFICATION_DISABLED;
    //         }
    //         // Call the application event handler.
    //         p_cus->evt_handler(p_cus, &evt);
    //     }
    // }
}

void ble_cus_pb_on_ble_evt(ble_evt_t const* p_ble_evt, void* p_context)
{
    ble_cus_pb_t* p_cus = (ble_cus_pb_t*)p_context;

    // NRF_LOG_INFO("BLE event received. Event type = %d\r\n", p_ble_evt->header.evt_id);
    if (p_cus == NULL || p_ble_evt == NULL)
    {
        return;
    }

    switch (p_ble_evt->header.evt_id)
    {
    case BLE_GAP_EVT_CONNECTED:
        on_connect(p_cus, p_ble_evt);
        break;

    case BLE_GAP_EVT_DISCONNECTED:
        on_disconnect(p_cus, p_ble_evt);
        break;

    case BLE_GATTS_EVT_WRITE:
        on_write(p_cus, p_ble_evt);
        break;
        /* Handling this event is not necessary
                case BLE_GATTS_EVT_EXCHANGE_MTU_REQUEST:
                    NRF_LOG_INFO("EXCHANGE_MTU_REQUEST event received.\r\n");
                    break;
        */
    case BLE_GATTS_EVT_RW_AUTHORIZE_REQUEST:
        // TODO: Here we can do stuff on read, like feed a timeout timer
        __NOP();
        break;
    default:
        // No implementation needed.
        break;
    }
}

uint32_t ble_cus_pb_init(ble_cus_pb_t* p_cus, const ble_cus_pb_init_t* p_cus_init)
{
    if (p_cus == NULL || p_cus_init == NULL)
    {
        return NRF_ERROR_NULL;
    }

    volatile uint32_t err_code;
    ble_uuid_t        service_uuid;

    // Initialize service structure
    p_cus->evt_handler = p_cus_init->evt_handler;
    p_cus->conn_handle = BLE_CONN_HANDLE_INVALID;

    // Add Custom Service UUID
    ble_uuid128_t base_uuid = {CUSTOM_SERVICE_UUID_BASE};

    BLE_UUID_BLE_ASSIGN(service_uuid, CUSTOM_SERVICE_UUID);

    // Add the Custom Service
    err_code = sd_ble_gatts_service_add(BLE_GATTS_SRVC_TYPE_PRIMARY, &service_uuid, &(p_cus->service_handle));
    VERIFY_SUCCESS(err_code);

    err_code = sd_ble_uuid_vs_add(&base_uuid, &service_uuid.type);
    VERIFY_SUCCESS(err_code);

    // Add Sensor data characteristic
    err_code = char_pb_sensors_add_to_service(p_cus);
    VERIFY_SUCCESS(err_code);

    return err_code;
}