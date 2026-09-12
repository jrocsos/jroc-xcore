#include <stdint.h>

void jroc_scheduler_runtime_init(void);
int jroc_scheduler_enqueue(uint32_t);
uint32_t jroc_scheduler_current_pid(void);
uint32_t jroc_scheduler_tick(void);
uint32_t jroc_scheduler_queue_size(void);

int main(void)
{
    jroc_scheduler_runtime_init();

    if (jroc_scheduler_enqueue(1) != 0)
        return 1;

    if (jroc_scheduler_enqueue(2) != 0)
        return 2;

    if (jroc_scheduler_queue_size() != 2)
        return 3;

    if (jroc_scheduler_current_pid() != 1)
        return 4;

    if (jroc_scheduler_tick() != 2)
        return 5;

    if (jroc_scheduler_tick() != 1)
        return 6;

    return 0;
}
