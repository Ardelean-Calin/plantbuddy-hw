#include "task_scheduler.h"
#include "app_timer.h"
#include "datalogger.h"
#include "sensors.h"
#include "unix_time.h"
#include <stdint.h>

APP_TIMER_DEF(m_periodic_timer); // App timer used by the scheduler
uint32_t scheduler_counter;

/* Static function prototypes */
static void scheduler_run_100ms(void* p_context);
static void scheduler_run_1000ms();
static void scheduler_run_10000ms();
static void scheduler_invoke_other_tasks(uint32_t count);

void scheduler_init()
{
    ret_code_t err_code;
    scheduler_counter = 0;

    // Create apptimer
    err_code = app_timer_create(&m_periodic_timer, APP_TIMER_MODE_REPEATED, scheduler_run_100ms);
    APP_ERROR_CHECK(err_code);
}

void scheduler_start()
{
    ret_code_t err_code;

    // Start timer
    err_code = app_timer_start(m_periodic_timer, APP_TIMER_TICKS(100), NULL); // 100ms timer
    APP_ERROR_CHECK(err_code);
}

void scheduler_stop()
{
    ret_code_t err_code;

    // Stop timer
    err_code = app_timer_stop(m_periodic_timer);
    APP_ERROR_CHECK(err_code);
}

/** Static function definitions BEGIN **/

/**
 * @brief Run the periodic tasks with a period of 100ms
 */
static void scheduler_run_100ms(void* p_context)
{
    /* Invoke the 1s and 10s tasks as needed */
    scheduler_counter++;
    scheduler_invoke_other_tasks(scheduler_counter);
};

/**
 * @brief Run the periodic tasks with a period of 1000ms
 */
static void scheduler_run_1000ms()
{
    /* Run our 1000ms tasks */
    unix_time_task();
    // datalogger_task();
};

/**
 * @brief Run the periodic tasks with a period of 10000ms
 */
static void scheduler_run_10000ms()
{
    /* Run our 10000ms tasks */
    sensors_task();
};

/**
 * @brief Decides whether other scheduling tasks need to be run.
 */
static void scheduler_invoke_other_tasks(uint32_t count)
{
    if (count % 10 == 0)
    {
        scheduler_run_1000ms();
    }

    if (count % 100 == 0)
    {
        scheduler_run_10000ms();
    }

    /* Reset the counter at 4 billion, this way we can go on forever */
    if (count == 4000000000)
    {
        count = 0;
    }
}
/** Static function definitions END **/
