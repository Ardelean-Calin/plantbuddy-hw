#pragma once

#include <stdint.h>

#define OPT3001_ADDR      0x44
#define OPT3001_EXP_MASK  0xF0
#define OPT3001_READ_MASK 0xFFF

/**
 * Register addresses of the sensor.
 */
typedef enum OPT3001_REGISTER
{
    OPT3001_RESULT          = 0x00,
    OPT3001_CONFIG          = 0x01,
    OPT3001_LOW_LIMIT       = 0x02,
    OPT3001_HIGH_LIMIT      = 0x03,
    OPT3001_MANUFACTURER_ID = 0x7E,
    OPT3001_DEVICE_ID       = 0x7F,
} OPT3001_reg_t;

/**
 * Operation modes of the sensor
 */
typedef enum OPT3001_MODE
{
    SHUTDOWN    = 0b00, // Default - low power state
    SINGLE_SHOT = 0b01, // Shut down after a signle conversion
    CONTINUOUS  = 0b10  // Continuous conversions
} OPT3001_mode_t;

/**
 * Conversion/integration time for the sensor.
 * Longer integration time allows for a lower noise measurement.
 * Short integration time can also limit the effective full-scale range of
 * the sensor's measurements.
 */
typedef enum OPT3001_CONVERSION_TIME
{
    OPT3001_100MS = 0, // 100ms conversion time
    OPT3001_800MS = 1, // 800ms conversion time
} OPT3001_conv_time_t;

/**
 * Interrupt mode of the sensor.
 * Interrupts can either be latched, requiring the sensor be manually read
 * to clear the interrupt state, or self-clearing once the triggering event
 * passes.
 *
 * Interrupts are caused by sensor measurements falling outside the set
 * low and high limits. Such instances are referred to as 'fault' events
 * in the sensor's datasheet.
 */
typedef enum OPT3001_INTERRUPT_MODE
{
    OPT_INT_HYSTERESIS = 0, // Self-clearing after triggering condition passes
    OPT_INT_LATCHED    = 1, // User-cleared interrupts
} OPT3001_interrupt_mode_t;

/**
 * Polarity of the sensor's interrupts.
 * Can be active-high or active low.
 * Active-low interrupts require a pull-up resistor on the INT pin.
 */
typedef enum OPT3001_INTERRUPT_POLARITY
{
    ACTIVE_LOW  = 0,
    ACTIVE_HIGH = 1,
} OPT3001_interrupt_polarity_t;

/**
 * The full-scale range of the sensor in nW/cm^2
 * Full-scale ranges have been approximated in the following labels.
 * Refer to the sensor datasheet for the exact ranges.
 */
typedef enum OPT3001_RANGE
{
    OPT3001_RANGE_AUTO = 0b1100,
    OPT3001_RANGE_40   = 0,
    OPT3001_RANGE_80   = 1,
    OPT3001_RANGE_160  = 2,
    OPT3001_RANGE_320  = 3,
    OPT3001_RANGE_640  = 4,
    OPT3001_RANGE_1K3  = 5,
    OPT3001_RANGE_2K6  = 6,
    OPT3001_RANGE_5K2  = 7,
    OPT3001_RANGE_10K  = 8,
    OPT3001_RANGE_21K  = 9,
    OPT3001_RANGE_42K  = 10,
    OPT3001_RANGE_84K  = 11,
} OPT3001_range_t;

/**
 * Number of 'faults' required to trigger an interrupt.
 * A fault is described as an instance of the measured signal
 * being outside the user-set low or high limits.
 */
typedef enum OPT3001_FAULT_CONFIG
{
    OPT3001_FAULT_1 = 0,
    OPT3001_FAULT_2 = 1,
    OPT3001_FAULT_4 = 2,
    OPT3001_FAULT_8 = 3
} OPT3001_fault_count_t;

/**
 * Configuration options for the sensor.
 * The contents of the OPT3001_config_t type reflect that of the sensor's
 * configuration register, which is 16 bits wide.
 *
 * Some values in the configuration register are read-only and reflect
 * the state of the sensor, rather than control its operating characteristics.
 */
typedef union
{
    struct
    {
        uint8_t fault_interrupt_count : 2; // Number of measurements outside set levels required to trigger interrupt
        uint8_t mask_exponent : 1;         // Not sure...
        uint8_t interrupt_polarity : 1;    // Polarity of interrupt signal [active high, active low]
        uint8_t interrupt_mode : 1;        // Interrupt latch mode [transient, latched]
        uint8_t flag_low : 1;              // Read-only. 1: Conversion lower than user's low limit
        uint8_t flag_high : 1;             // Read-only. 1: Conversion larger than user's high limit
        uint8_t conversion_ready : 1;      // Read-only. 1: Conversion complete
        uint8_t overflow : 1;              // Read-only. 1: ADC overflow
        uint8_t mode : 2;                  // Conversion mode. [shutdown, single conversion, continuous conversion]
        uint8_t conversion_time : 1;       // [100, 800] ms conversion time
        uint8_t range : 4;                 // Full-scale range of measurements
    };
    uint16_t raw;
} PACKED OPT3001_config_t;

/**
 * Result format of the sensor's measurements
 * Measurements are split into a fractional reading, and an exponent.
 * The optical power of a reading can be calculated as:
 *  OP = fractional_reading * 2^exponent * 1.2 [nW/cm^2]
 *
 * The same result format is used when setting the upper or lower level limits
 * of the sensor.
 */
typedef struct
{
    uint8_t raw[2];
} OPT3001_result_t;
