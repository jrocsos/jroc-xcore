#include <assert.h>
#include <stdint.h>

void jroc_timer_scheduler_init(uint32_t);
uint32_t jroc_timer_scheduler_irq(void);

int main(void)
{
    jroc_timer_scheduler_init(3);

    assert(jroc_timer_scheduler_irq() == 0);
    assert(jroc_timer_scheduler_irq() == 0);
    assert(jroc_timer_scheduler_irq() == 1);

    return 0;
}
