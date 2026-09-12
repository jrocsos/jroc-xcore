#include <stdint.h>

static volatile uint32_t timer_ticks = 0;
static uint32_t timer_hz = 100;

void jroc_timer_runtime_init(uint32_t hz)
{
    if (hz != 0)
        timer_hz = hz;

    timer_ticks = 0;
}

void jroc_timer_irq(void)
{
    timer_ticks++;
}

uint32_t jroc_timer_ticks(void)
{
    return timer_ticks;
}

uint32_t jroc_timer_hz(void)
{
    return timer_hz;
}
