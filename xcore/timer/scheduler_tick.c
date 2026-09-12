#include <stdint.h>

static uint32_t ticks = 0;
static uint32_t quantum = 10;
static uint32_t slice = 0;

void jroc_timer_scheduler_init(uint32_t quantum_ticks)
{
    ticks = 0;
    slice = 0;

    if (quantum_ticks)
        quantum = quantum_ticks;
}

uint32_t jroc_timer_scheduler_irq(void)
{
    ticks++;
    slice++;

    if (slice >= quantum)
    {
        slice = 0;
        return 1;
    }

    return 0;
}

uint32_t jroc_timer_scheduler_ticks(void)
{
    return ticks;
}
