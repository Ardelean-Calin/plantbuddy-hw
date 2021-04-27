#include "char_timestamp.h"
#include "ble_gattc.h"
#include "sdk_common.h"
#include <stdint.h>
#include <string.h>

static ble_cus_pb_t* p_cus_local = NULL;

/**
 * @brief Function for adding the timestamp characteristic to a service.
 *
 * @param[in]   p_cus        PlantBuddy Service structure.
 *
 * @return      NRF_SUCCESS on success, otherwise an error code.
 */
uint32_t char_timestamp_add_to_service(ble_cus_pb_t* p_cus)
{
    ret_code_t               err_code;
    ble_add_char_params_t    add_char_params;
    ble_add_char_user_desc_t add_char_user_desc;
    ble_gatt_char_props_t    gatt_char_props;
    static char*             user_desc_text  = "Device timestamp";
    uint32_t                 initial_ena_val = 0U;

    p_cus_local = p_cus;

    /* Add the Sensor Data characteristic */
    memset(&add_char_params, 0, sizeof(add_char_params));
    add_char_params.uuid              = TIMESTAMP_CHAR_UUID;
    add_char_params.uuid_type         = p_cus->uuid_type;
    add_char_params.init_len          = sizeof(uint32_t);
    add_char_params.p_init_value      = (uint8_t*)&initial_ena_val;
    add_char_params.max_len           = sizeof(uint32_t);
    add_char_params.char_props.read   = 1;
    add_char_params.char_props.write  = 1;
    add_char_params.char_props.notify = 0;
    add_char_params.is_var_len        = false;
    add_char_params.read_access       = SEC_OPEN;
    add_char_params.write_access      = SEC_OPEN;      // Possible to write
    add_char_params.cccd_write_access = SEC_NO_ACCESS; // No notifications

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
    err_code = characteristic_add(p_cus->service_handle, &add_char_params, &(p_cus->char_timestamp_h));
    VERIFY_SUCCESS(err_code);

    return err_code;
}