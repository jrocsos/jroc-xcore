#include <stdint.h>

#define JROC_MAX_PROCESSES 64

static uint32_t run_queue[JROC_MAX_PROCESSES];
static uint32_t queue_length = 0;
static uint32_t current_index = 0;
static int scheduler_ready = 0;

void jroc_scheduler_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        run_queue[i] = 0;

    queue_length = 0;
    current_index = 0;
    scheduler_ready = 1;
}

int jroc_scheduler_add(uint32_t pid)
{
    if (!scheduler_ready)
        return -1;

    if (queue_length >= JROC_MAX_PROCESSES)
        return -1;

    run_queue[queue_length++] = pid;

    return 0;
}

uint32_t jroc_scheduler_current(void)
{
    if (!queue_length)
        return 0;

    return run_queue[current_index];
}

uint32_t jroc_scheduler_next(void)
{
    if (!queue_length)
        return 0;

    current_index++;

    if (current_index >= queue_length)
        current_index = 0;

    return run_queue[current_index];
}

uint32_t jroc_scheduler_queue_length(void)
{
    return queue_length;
}

int jroc_scheduler_status(void)
{
    return scheduler_ready;
}
