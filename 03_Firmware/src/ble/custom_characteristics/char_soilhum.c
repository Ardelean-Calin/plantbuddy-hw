#include <stdint.h>
#include <string.h>

#include "ble_gattc.h"
#include "char_soilhum.h"
#include "sdk_common.h"
#include "sdk_errors.h"

/**
 * @brief Function for adding the soil humidity characteristic.
 *
 * @param[in]   p_cus        PlantBuddy Service structure.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_soilhum_add_to_service(ble_cus_pb_t* p_cus)
{
    ret_code_t               err_code;
    ble_add_char_params_t    add_char_params;
    ble_add_char_user_desc_t add_char_user_desc;
    ble_gatt_char_props_t    gatt_char_props;
    static char*             user_desc_text  = "Soil humidity";
    soilhum_t                initial_ena_val = 0;

    /* Add the soil humidity characteristic */
    memset(&add_char_params, 0, sizeof(add_char_params));
    add_char_params.uuid              = SOIL_HUM_CHAR_UUID;
    add_char_params.uuid_type         = p_cus->uuid_type;
    add_char_params.init_len          = sizeof(soilhum_t);
    add_char_params.p_init_value      = (uint8_t*)&initial_ena_val;
    add_char_params.max_len           = sizeof(soilhum_t);
    add_char_params.char_props.read   = 1;
    add_char_params.char_props.write  = 0;
    add_char_params.char_props.notify = 1;

    add_char_params.read_access       = SEC_OPEN;
    add_char_params.write_access      = SEC_NO_ACCESS; // Not possible to write
    add_char_params.cccd_write_access = SEC_OPEN;      // Obligatory for notifications to work!

    // /* Initialize Characteristic Descriptor */
    memset(&add_char_user_desc, 0, sizeof(add_char_user_desc));
    add_char_user_desc.max_size         = strlen(user_desc_text);
    add_char_user_desc.size             = strlen(user_desc_text);
    add_char_user_desc.p_char_user_desc = (uint8_t*)user_desc_text;
    add_char_user_desc.is_var_len       = false;
    add_char_user_desc.read_access      = SEC_OPEN;
    add_char_user_desc.write_access     = SEC_NO_ACCESS;

    add_char_params.p_user_descr = &add_char_user_desc;

    /* Register the characteristic */
    err_code = characteristic_add(p_cus->service_handle, &add_char_params, &(p_cus->char_soilhum_handle));
    VERIFY_SUCCESS(err_code);

    return err_code;
}

/**
 * @brief Function for updating the soil humidity characteristic.
 *
 * @param[in]   p_cus       PlantBuddy Service structure.
 * @param[in]   new_soilhum   New value of the soil humidity.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_soilhum_update(ble_cus_pb_t* p_cus, soilhum_t new_soilhum)
{
    if (p_cus == NULL)
    {
        return NRF_ERROR_NULL;
    }

    uint32_t          err_code = NRF_SUCCESS;
    ble_gatts_value_t gatts_value;

    // Initialize value struct.
    memset(&gatts_value, 0, sizeof(gatts_value));

    gatts_value.len     = sizeof(soilhum_t);
    gatts_value.offset  = 0;
    gatts_value.p_value = (uint8_t*)&new_soilhum;

    // Update database.
    err_code = sd_ble_gatts_value_set(p_cus->conn_handle, p_cus->char_soilhum_handle.value_handle, &gatts_value);
    if (err_code != NRF_SUCCESS)
    {
        return err_code;
    }

    // Send value if connected and notifying.
    if ((p_cus->conn_handle != BLE_CONN_HANDLE_INVALID))
    {
        ble_gatts_hvx_params_t hvx_params;

        memset(&hvx_params, 0, sizeof(hvx_params));

        hvx_params.handle = p_cus->char_soilhum_handle.value_handle;
        hvx_params.type   = BLE_GATT_HVX_NOTIFICATION;
        hvx_params.offset = gatts_value.offset;
        hvx_params.p_len  = &gatts_value.len;
        hvx_params.p_data = gatts_value.p_value;

        err_code = sd_ble_gatts_hvx(p_cus->conn_handle, &hvx_params);
    }
    else
    {
        err_code = NRF_ERROR_INVALID_STATE;
    }

    return err_code;
}