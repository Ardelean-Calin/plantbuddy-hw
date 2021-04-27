#pragma once

#include "nrf_twi_mngr.h"
#include "opt3001.h"
#include "opt3001_types.h"

#define OPT3001_CFG_CONVERSION_TIME    OPT3001_800MS
#define OPT3001_CFG_CONVERSION_TIME_MS (OPT3001_CFG_CONVERSION_TIME == OPT3001_800MS ? 880 : 110)

// clang-format off
// TODO: I Send address both times, need to only send it one time...
#define OPT3001_WRITE(p_buffer, byte_cnt) \
    NRF_TWI_MNGR_WRITE(OPT3001_ADDR, p_buffer, byte_cnt, 0)

#define OPT3001_READ(p_reg_addr, p_buffer, byte_cnt) \
    NRF_TWI_MNGR_WRITE(OPT3001_ADDR, p_reg_addr, 1, 0), \
    NRF_TWI_MNGR_READ(OPT3001_ADDR, p_buffer, byte_cnt, 0)
// clang-format on

/* Helper macros */
#define OPT3001_TRANSACTION_DEF(t_name, p_transfers_local, p_callback)                   \
    static nrf_twi_mngr_transaction_t NRF_TWI_MNGR_BUFFER_LOC_IND t_name = {             \
        .callback            = p_callback,                                               \
        .p_user_data         = NULL,                                                     \
        .p_transfers         = p_transfers_local,                                        \
        .number_of_transfers = sizeof(p_transfers_local) / sizeof(p_transfers_local[0]), \
        .p_required_twi_cfg  = NULL,                                                     \
    }

#define OTP3001_WRITE_TRANSFER_DEF(reg_addr, data, transfer_name)   \
    static opt3001_packet_t const CONCAT_2(transfer_name, _cfg) = { \
        .address = reg_addr,                                        \
        .config  = data,                                            \
    };                                                              \
    static nrf_twi_mngr_transfer_t const transfer_name[] = {        \
        OPT3001_WRITE(&CONCAT_2(transfer_name, _cfg), 3),           \
    }

#define OTP3001_READ_TRANSFER_DEF(reg_addr, p_buffer, transfer_name)                       \
    static uint8_t                       CONCAT_2(transfer_name, _reg_addr) = reg_addr;    \
    static nrf_twi_mngr_transfer_t const transfer_name[]                    = {            \
        OPT3001_READ(&CONCAT_2(transfer_name, _reg_addr), p_buffer, 2), \
    }

#define OPT3001_EXP_EXTRACT(byte) ((byte & OPT3001_EXP_MASK) >> 4)
/* Helper macros END */

void            drv_opt3001_init(nrf_twi_mngr_t* twi_mngr_ptr);
void            drv_opt3001_meas_start(void);
luminous_flux_t drv_opt3001_get_lumflux(void);