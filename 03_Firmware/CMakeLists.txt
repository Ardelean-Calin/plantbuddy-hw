cmake_minimum_required(VERSION 3.15.3)

project(PlantBuddy)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set (SOURCE
        Src/main.c
        Src/BlueNRG1_it.c
        Src/shtc3.c
        Src/led.c
        Src/soilhum.c
        Src/ble.c
        hal/src/clock.c
        hal/src/fifo.c
        hal/src/gp_timer.c
        hal/src/hal_radio.c
        hal/src/miscutil.c
        hal/src/osal.c
        hal/src/radio_ota.c
        hal/src/sleep.c
        i2c/i2c.c
        opt3001/opt3001.c
        CMSIS/Device/ST/BlueNRG1/Source/system_bluenrg1.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_adc.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_dma.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_flash.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_gpio.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_i2c.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_mft.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_pka.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_radio.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_rng.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_rtc.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_spi.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_sysCtrl.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_timer.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_uart.c
        BlueNRG1_Periph_Driver/src/BlueNRG1_wdg.c
        BlueNRG1_Periph_Driver/src/misc.c
        FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
        FreeRTOS/Source/portable/MemMang/heap_1.c
        FreeRTOS/Source/croutine.c
        FreeRTOS/Source/event_groups.c
        FreeRTOS/Source/list.c
        FreeRTOS/Source/queue.c
        FreeRTOS/Source/stream_buffer.c
        FreeRTOS/Source/tasks.c
        FreeRTOS/Source/timers.c
        FreeRTOS/BlueNRG/freertos_lp.c
        Bluetooth_LE/src/stack_dle_api_stubs.c
        Bluetooth_LE/src/stack_priv_api_stubs.c
        Bluetooth_LE/src/stack_sc_api_stubs.c
        Bluetooth_LE/src/stack_slvonly_api_stubs.c
        Bluetooth_LE/src/stack_user_cfg.c
        BLE_Application/Utils/src/ble_utils.c
        hal/src/context_switch.s
        inc/memory_map.h
    )


set(EXECUTABLE ${PROJECT_NAME}.out)

add_executable(${EXECUTABLE} ${SOURCE})

target_compile_definitions(${EXECUTABLE} PRIVATE
        -DBLUENRG1_DEVICE
        -DSMPS_INDUCTOR=SMPS_INDUCTOR_10uH
        -DNO_SMART_POWER_MANAGEMENT
        )

target_include_directories(${EXECUTABLE} PRIVATE
        Inc
        BlueNRG1_Periph_Driver/inc
        CMSIS/Device/ST/BlueNRG1/Include
        CMSIS/Include
        hal/inc
        FreeRTOS/Source/include
        FreeRTOS/Source/portable/GCC/ARM_CM0
        FreeRTOS/BlueNRG/
        Bluetooth_LE/inc
        BLE_Application/layers_inc
        BLE_Application/Utils/inc
        i2c
        opt3001
        )

target_compile_options(${EXECUTABLE} PRIVATE
        -mcpu=cortex-m0
        -mthumb

        -fdata-sections
        -ffunction-sections

        -Wall

        $<$<CONFIG:Debug>:-Og>
        )

target_link_options(${EXECUTABLE} PRIVATE
        -T${CMAKE_SOURCE_DIR}/memory_map.ld
        -T${CMAKE_SOURCE_DIR}/app.ld
        -mcpu=cortex-m0
        -mthumb
        -specs=nano.specs
        -lc
        -lm
        -lnosys
        -Wl,-Map=${PROJECT_NAME}.map,--cref
        -Wl,--gc-sections
        -Wl,--print-memory-usage
        )

target_link_libraries(${EXECUTABLE} ${CMAKE_SOURCE_DIR}/Bluetooth_LE/library/libbluenrg1_stack.a)

# Print executable size
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-size ${EXECUTABLE})

# Create hex file
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin)