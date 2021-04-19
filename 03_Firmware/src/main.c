/**
 * Copyright (c) 2014 - 2020, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** @file
 *
 * @defgroup PlantBuddy main.c
 * @{
 * @ingroup plantbuddy
 * @brief PlantBuddy main file.
 *
 * This file contains the source code for a PlantBuddy.
 *
 */

#include "app_scheduler.h"
#include "app_timer.h"
#include "ble_app.h"
#include "ble_dfu.h"
#include "nrf.h"
#include "nrf_delay.h"
#include "nrf_drv_clock.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_saadc.h"
#include "nrf_error.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_pwr_mgmt.h"
#include "nrf_soc.h"
#include "sensors.h"
#include "status.h"
#include <stdbool.h>
#include <stdint.h>

// Scheduler settings
#define SCHED_MAX_EVENT_DATA_SIZE MAX(sizeof(nrf_drv_saadc_evt_t), APP_TIMER_SCHED_EVENT_DATA_SIZE)
#define SCHED_QUEUE_SIZE          10

static void app_softtimers_init(void);
static void idle_state_handle(void);
static void lfclk_init(void);
static void ppi_init(void);
static void power_management_init(void);
static bool app_shutdown_handler(nrf_pwr_mgmt_evt_t event);

/**
 * @brief Register application shutdown handler with priority 0.
 */
NRF_PWR_MGMT_HANDLER_REGISTER(app_shutdown_handler, 0);

/**
 * @brief Initialize the apptimer module.
 */
static void app_softtimers_init(void)
{
    ret_code_t err_code;
    err_code = app_timer_init();
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Function for handling the idle state (main loop).
 *
 * @details If there is no pending log operation, then sleep until next the next event occurs.
 */
static void idle_state_handle(void)
{
    // if (NRF_LOG_PROCESS() == false)
    // {
    nrf_pwr_mgmt_run();
    // }
}

/**
 * @brief Function starting the internal LFCLK oscillator.
 *
 * @details This is needed by RTC1 which is used by the Application Timer
 *          (When SoftDevice is enabled the LFCLK is always running and this is not needed).
 */
static void lfclk_init(void)
{
    ret_code_t err_code;
    err_code = nrf_drv_clock_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_clock_lfclk_request(NULL);
}

/**
 * @brief Function for initializing power management.
 */
static void power_management_init(void)
{
    ret_code_t err_code;
    err_code = nrf_pwr_mgmt_init();
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Initialize PPI
 */
static void ppi_init(void)
{
    ret_code_t err_code;
    err_code = nrf_drv_ppi_init();
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Power management handler.
 */
static bool app_shutdown_handler(nrf_pwr_mgmt_evt_t event)
{
    switch (event)
    {
    case NRF_PWR_MGMT_EVT_PREPARE_DFU:
        // NRF_LOG_INFO("Power management wants to reset to DFU mode\r\n");
        // Change this code to tailor to your reset strategy.
        // Returning false here means that the device is not ready to jump to DFU mode yet.
        //
        // Here is an example using a variable to delay resetting the device:
        // if (!m_ready_for_reset)
        // {
        //     return false;
        // }
        break;

    default:
        // Implement any of the other events available from the power management module:
        //      -NRF_PWR_MGMT_EVT_PREPARE_SYSOFF
        //      -NRF_PWR_MGMT_EVT_PREPARE_WAKEUP
        //      -NRF_PWR_MGMT_EVT_PREPARE_RESET
        return true;
    }
    // NRF_LOG_INFO("Power management allowed to reset to DFU mode\r\n");
    return true;
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    ret_code_t err_code;

#if NRFX_CHECK(NRF_LOG_ENABLED)
    NRF_LOG_INIT(NULL);
    NRF_LOG_DEFAULT_BACKENDS_INIT();
#endif

#ifndef DEBUG
    // Initialize the async SVCI interface to bootloader before any interrupts are enabled.
    err_code = ble_dfu_buttonless_async_svci_init();
    APP_ERROR_CHECK(err_code);
#endif

    // Initialize low-frequency clock which will then be used by our software timer
    lfclk_init();
    // Initialize PPI
    ppi_init();
    // Initialize app timer module
    app_timer_init();
    // Initialize power manager
    power_management_init();

    /* Initialize app scheduler */
    APP_SCHED_INIT(SCHED_MAX_EVENT_DATA_SIZE, SCHED_QUEUE_SIZE);

    /* Initialize our different modules */
    status_init();
    sensors_init();

    // Enable DC-DC converter for reduced power consumption!
    sd_power_dcdc_mode_set(NRF_POWER_DCDC_ENABLE);

    // Start the BLE Interface
    ble_app_init();
    while (1)
    {
        // App scheduler manages items in the queue
        app_sched_execute();
        idle_state_handle();
    }
}
