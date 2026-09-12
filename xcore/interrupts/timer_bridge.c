#include <stdint.h>

uint32_t jroc_timer_scheduler_irq(void);
uint32_t jroc_scheduler_tick(void);

static uint32_t last_pid = 0;

void jroc_timer_irq_scheduler_bridge(void)
{
    if (jroc_timer_scheduler_irq())
        last_pid = jroc_scheduler_tick();
}

uint32_t jroc_last_scheduler_pid(void)
{
    return last_pid;
}
