#include <stdint.h>

#define JROC_RUN_QUEUE 64

static uint32_t queue[JROC_RUN_QUEUE];
static uint32_t length = 0;
static uint32_t current = 0;

void jroc_runtime_scheduler_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_RUN_QUEUE; i++)
        queue[i] = 0;

    length = 0;
    current = 0;
}

int jroc_runtime_scheduler_add(uint32_t pid)
{
    if (length >= JROC_RUN_QUEUE)
        return -1;

    queue[length++] = pid;
    return 0;
}

uint32_t jroc_runtime_scheduler_current(void)
{
    if (!length)
        return 0;

    return queue[current];
}

uint32_t jroc_runtime_scheduler_next(void)
{
    if (!length)
        return 0;

    current++;

    if (current >= length)
        current = 0;

    return queue[current];
}
