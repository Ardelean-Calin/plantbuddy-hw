#pragma once

typedef enum
{
    IDLE = 0,
    MEASURING,

} soilhum_state_t;

void soilhum_init(void);
void soilhum_sm_tick(void);