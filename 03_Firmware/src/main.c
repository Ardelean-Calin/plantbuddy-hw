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
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 * This file contains the source code for a sample application to blink LEDs.
 *
 */

#include "app_timer.h"
#include "nrf_delay.h"
#include "nrf_drv_clock.h"
#include "nrf_drv_gpiote.h"
#include <stdbool.h>
#include <stdint.h>

#define LEDY_PIN 20
#define LEDR_PIN 18

APP_TIMER_DEF(m_repeated_timer_id_100ms); /**< Handler for repeated timer used to execute main State Machine. */

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
 * @brief Initializes all used GPIOTE's with the proper configuration.
 */
static void gpiote_init(void)
{
    ret_code_t err_code;
    // Only initialize driver if it's not already initialized.
    if (!nrf_drv_gpiote_is_init())
    {
        err_code = nrf_drv_gpiote_init();
        APP_ERROR_CHECK(err_code);
    }

    nrf_drv_gpiote_out_config_t config = NRFX_GPIOTE_CONFIG_OUT_SIMPLE(false);

    // Configure output pins
    nrf_drv_gpiote_out_init(LEDY_PIN, &config);
    nrf_drv_gpiote_out_init(LEDR_PIN, &config);
}

/**
 * @brief Timeout handler for the repeated timer. State machine invocation goes here.
 */
static void periodic_handler_100ms(void* p_context)
{
    // Call the main state machine! To be defined in another file
    // sm_main_tick();
    
    // For now also toggle the LED to see activity.
    nrf_drv_gpiote_out_toggle(LEDR_PIN);
}

/**
 * @brief Create timers.
 */
static void create_timers()
{
    ret_code_t err_code;

    // Create timers
    err_code = app_timer_create(&m_repeated_timer_id_100ms, APP_TIMER_MODE_REPEATED, periodic_handler_100ms);
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Starts the previously created timers with given periodicity.
 */
static void start_timers()
{
    ret_code_t err_code;

    // Start timers
    err_code = app_timer_start(m_repeated_timer_id_100ms, APP_TIMER_TICKS(100), NULL); // 100ms timer
    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    ret_code_t errCode;
    // Initialize low-frequency clock which will then be used by our software timer
    lfclk_init();
    // Initialize GPIOTE module & pins
    gpiote_init();

    // TO-DO: Use the application timer for periodic execution of global state machine every 100ms:
    // https://devzone.nordicsemi.com/nordic/short-range-guides/b/software-development-kit/posts/application-timer-tutorial
    // This method is VERY low power!
    errCode = app_timer_init();
    APP_ERROR_CHECK(errCode);

    create_timers();
    start_timers();

    // Use the Scheduler and scheduler hooks to execute stuff on interrupts!
    // https://devzone.nordicsemi.com/nordic/short-range-guides/b/software-development-kit/posts/scheduler-tutorial

    // BLE Characteristics tutorial:
    // https://devzone.nordicsemi.com/nordic/short-range-guides/b/bluetooth-low-energy/posts/ble-characteristics-a-beginners-tutorial
}

/**
 *@}
 **/
