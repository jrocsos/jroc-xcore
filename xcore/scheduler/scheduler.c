#include <stdint.h>

#define JROC_QUEUE_MAX 64

static uint32_t queue[JROC_QUEUE_MAX];
static uint32_t length;
static uint32_t current;
static int ready;

void jroc_scheduler_init(void)
{
    length = 0;
    current = 0;
    ready = 1;
}

int jroc_scheduler_add(uint32_t pid)
{
    if (!ready || length >= JROC_QUEUE_MAX)
        return -1;

    queue[length++] = pid;
    return 0;
}

uint32_t jroc_scheduler_current(void)
{
    if (!length)
        return 0;

    return queue[current];
}

uint32_t jroc_scheduler_next(void)
{
    if (!length)
        return 0;

    current++;

    if (current >= length)
        current = 0;

    return queue[current];
}

int jroc_scheduler_status(void)
{
    return ready;
}
