#include "ble_cus_pb.h"
#include "ble_gattc.h"
#include "downloader.h"
#include "sdk_common.h"
#include "sdk_errors.h"

/**
 * We use a control scheme to download data packets, like so:
 * 1) We write to the control characteristic:
 *
 *
 *
 *
 */

// void char_downloader_on_request(download_request_t request_type);

static ble_cus_pb_t* p_cus_local = NULL;

/**
 * @brief Function for adding the downloader read characteristic to a service.
 *
 * @param[in]   p_cus        PlantBuddy Service structure.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_downloader_read_add_to_service(ble_cus_pb_t* p_cus)
{
    ret_code_t               err_code;
    ble_add_char_params_t    add_char_params;
    ble_add_char_user_desc_t add_char_user_desc;
    ble_gatt_char_props_t    gatt_char_props;
    static char*             user_desc_text  = "DWNLD READ";
    downloader_packet_t      initial_ena_val = {0};

    p_cus_local = p_cus;

    /* Add the downloader read characteristic */
    memset(&add_char_params, 0, sizeof(add_char_params));
    add_char_params.uuid              = DOWNLOADER_READ_CHAR_UUID;
    add_char_params.uuid_type         = p_cus->uuid_type;
    add_char_params.init_len          = sizeof(downloader_packet_t);
    add_char_params.p_init_value      = (uint8_t*)&initial_ena_val;
    add_char_params.max_len           = sizeof(downloader_packet_t);
    add_char_params.char_props.read   = 1;
    add_char_params.char_props.write  = 0;
    add_char_params.char_props.notify = 1;

    add_char_params.read_access       = SEC_OPEN;
    add_char_params.write_access      = SEC_NO_ACCESS; // Not possible to write
    add_char_params.cccd_write_access = SEC_OPEN;      // Obligatory for notifications to work!

    /* Initialize Characteristic Descriptor */
    memset(&add_char_user_desc, 0, sizeof(add_char_user_desc));
    add_char_user_desc.max_size         = strlen(user_desc_text);
    add_char_user_desc.size             = strlen(user_desc_text);
    add_char_user_desc.p_char_user_desc = (uint8_t*)user_desc_text;
    add_char_user_desc.is_var_len       = false;
    add_char_user_desc.read_access      = SEC_OPEN;
    add_char_user_desc.write_access     = SEC_NO_ACCESS;

    add_char_params.p_user_descr = &add_char_user_desc;

    /* Register the characteristic */
    err_code = characteristic_add(p_cus->service_handle, &add_char_params, &(p_cus->char_downloader_ctrl_h));
    VERIFY_SUCCESS(err_code);

    return err_code;
}

/**
 * @brief Function for adding the downloader control characteristic to a service.
 *
 * @param[in]   p_cus        PlantBuddy Service structure.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_downloader_ctrl_add_to_service(ble_cus_pb_t* p_cus)
{
    ret_code_t               err_code;
    ble_add_char_params_t    add_char_params;
    ble_add_char_user_desc_t add_char_user_desc;
    ble_gatt_char_props_t    gatt_char_props;
    static char*             user_desc_text  = "DWNLD CTRL";
    uint8_t                  initial_ena_val = 0;

    p_cus_local = p_cus;

    /* Add the downloader control characteristic */
    memset(&add_char_params, 0, sizeof(add_char_params));
    add_char_params.uuid              = DOWNLOADER_CTRL_CHAR_UUID;
    add_char_params.uuid_type         = p_cus->uuid_type;
    add_char_params.init_len          = sizeof(uint8_t);
    add_char_params.p_init_value      = (uint8_t*)&initial_ena_val;
    add_char_params.max_len           = sizeof(uint8_t);
    add_char_params.char_props.read   = 0;
    add_char_params.char_props.write  = 1;
    add_char_params.char_props.notify = 1;

    add_char_params.read_access       = SEC_OPEN;
    add_char_params.write_access      = SEC_NO_ACCESS; // Not possible to write
    add_char_params.cccd_write_access = SEC_OPEN;      // Obligatory for notifications to work!

    /* Initialize Characteristic Descriptor */
    memset(&add_char_user_desc, 0, sizeof(add_char_user_desc));
    add_char_user_desc.max_size         = strlen(user_desc_text);
    add_char_user_desc.size             = strlen(user_desc_text);
    add_char_user_desc.p_char_user_desc = (uint8_t*)user_desc_text;
    add_char_user_desc.is_var_len       = false;
    add_char_user_desc.read_access      = SEC_OPEN;
    add_char_user_desc.write_access     = SEC_NO_ACCESS;

    add_char_params.p_user_descr = &add_char_user_desc;

    /* Register the characteristic */
    err_code = characteristic_add(p_cus->service_handle, &add_char_params, &(p_cus->char_downloader_read_h));
    VERIFY_SUCCESS(err_code);

    return err_code;
}

/**
 * @brief Function for updating the download packet characteristic.
 *
 * @param[in]   new_sensor_data   New value of the download packet.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_downloader_update(downloader_packet_t* new_packet)
{
    if (p_cus_local == NULL)
    {
        return NRF_ERROR_NULL;
    }

    uint32_t          err_code = NRF_SUCCESS;
    ble_gatts_value_t gatts_value;

    // Initialize value struct.
    memset(&gatts_value, 0, sizeof(gatts_value));

    gatts_value.len     = sizeof(downloader_packet_t);
    gatts_value.offset  = 0;
    gatts_value.p_value = (uint8_t*)&new_packet;

    // Update database.
    err_code = sd_ble_gatts_value_set(
        p_cus_local->conn_handle, p_cus_local->char_downloader_read_h.value_handle, &gatts_value);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    // Send value if connected and notifying.
    if ((p_cus_local->conn_handle != BLE_CONN_HANDLE_INVALID))
    {
        ble_gatts_hvx_params_t hvx_params;

        memset(&hvx_params, 0, sizeof(hvx_params));

        hvx_params.handle = p_cus_local->char_sensordata_h.value_handle;
        hvx_params.type   = BLE_GATT_HVX_NOTIFICATION;
        hvx_params.offset = gatts_value.offset;
        hvx_params.p_len  = &gatts_value.len;
        hvx_params.p_data = gatts_value.p_value;

        err_code = sd_ble_gatts_hvx(p_cus_local->conn_handle, &hvx_params);
    }
    else
    {
        err_code = NRF_ERROR_INVALID_STATE;
    }

    return err_code;
}