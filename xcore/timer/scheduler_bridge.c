#include <stdint.h>

void jroc_timer_irq(void);
uint32_t jroc_scheduler_tick(void);

static uint32_t last_scheduled_pid = 0;

void jroc_timer_scheduler_tick(void)
{
    jroc_timer_irq();
    last_scheduled_pid = jroc_scheduler_tick();
}

uint32_t jroc_last_scheduled_pid(void)
{
    return last_scheduled_pid;
}
