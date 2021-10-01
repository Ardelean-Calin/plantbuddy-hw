#pragma once

#include "pb_config.h"
#include <stdint.h>

#define LTR303_MEAS_PERIOD_MS SENSORS_MEAS_PERIOD_MS
#define LTR303_PFACTOR        1.0f

#define LTR303_ADDRESS       0x29U
#define LTR303_PART_ID       0x86U
#define LTR303_MFC_ID        0x87U
#define LTR303_REG_CONTROL   0x80U
#define LTR303_REG_INTERRUPT 0x8FU
#define LTR303_REG_STATUS    0x8CU
#define LTR303_THRES_UP_0    0x97U
#define LTR303_THRES_UP_1    0x98U
#define LTR303_THRES_LOW_0   0x99U
#define LTR303_THRES_LOW_1   0x9AU
#define LTR303_DATA_CH1_0    0x88U
#define LTR303_DATA_CH1_1    0x89U
#define LTR303_DATA_CH0_0    0x8AU
#define LTR303_DATA_CH0_1    0x8BU

typedef enum LTR303_STATE
{
    LTR303_SM_IDLE = 0,
    LTR303_STARTUP,
    LTR303_READ_IDS,
    LTR303_CONFIG,
    LTR303_START,
    LTR303_WAIT_MEAS,
    LTR303_MEAS_DONE,
    LTR303_SLEEP,
    LTR303_ERROR
} eLTR303_STATE;

typedef float luminous_flux_t;

void            ltr303_init();
void            ltr303_sm_tick();
luminous_flux_t ltr303_get_luminous_flux();