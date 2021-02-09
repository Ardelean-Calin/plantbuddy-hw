/**
 * This is the main state machine. Will run periodically and update sensor values.
 *
 */

#include "statemachine.h"
#include <stdint.h>

extern uint32_t stateMachineTickCounter;

void statemachine_init(void){};
void statemachine_tick(void)
{
    // TODO: Add state-machine logic

    // Increment tick counter
    stateMachineTickCounter++;
};
void statemachine_deinit(void){};