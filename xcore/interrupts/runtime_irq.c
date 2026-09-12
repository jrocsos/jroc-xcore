#include <stdint.h>

static volatile uint32_t irq_count = 0;
static volatile uint32_t timer_irq_count = 0;

void jroc_irq_runtime_init(void)
{
    irq_count = 0;
    timer_irq_count = 0;
}

void jroc_irq_runtime_seen(uint8_t irq)
{
    irq_count++;

    if (irq == 0)
        timer_irq_count++;
}

uint32_t jroc_irq_count(void)
{
    return irq_count;
}

uint32_t jroc_timer_irq_count(void)
{
    return timer_irq_count;
}
