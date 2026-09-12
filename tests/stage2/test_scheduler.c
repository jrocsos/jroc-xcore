#include <stdint.h>

void jroc_scheduler_init(void);
int jroc_scheduler_add(uint32_t);
uint32_t jroc_scheduler_current(void);
uint32_t jroc_scheduler_next(void);

int main(void)
{
    jroc_scheduler_init();

    if (jroc_scheduler_add(10) != 0)
        return 1;

    if (jroc_scheduler_add(20) != 0)
        return 2;

    if (jroc_scheduler_current() != 10)
        return 3;

    if (jroc_scheduler_next() != 20)
        return 4;

    return 0;
}
