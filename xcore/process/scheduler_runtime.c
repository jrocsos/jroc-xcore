#include <stdint.h>

#define JROC_MAX_TASKS 64

static uint32_t run_queue[JROC_MAX_TASKS];
static uint32_t queue_size = 0;
static uint32_t current_task = 0;
static uint32_t ticks = 0;
static int scheduler_enabled = 0;

void jroc_scheduler_runtime_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_TASKS; i++)
        run_queue[i] = 0;

    queue_size = 0;
    current_task = 0;
    ticks = 0;
    scheduler_enabled = 1;
}

int jroc_scheduler_enqueue(uint32_t pid)
{
    if (!scheduler_enabled)
        return -1;

    if (queue_size >= JROC_MAX_TASKS)
        return -1;

    run_queue[queue_size++] = pid;

    return 0;
}

uint32_t jroc_scheduler_current_pid(void)
{
    if (queue_size == 0)
        return 0;

    return run_queue[current_task];
}

uint32_t jroc_scheduler_tick(void)
{
    ticks++;

    if (queue_size == 0)
        return 0;

    current_task++;

    if (current_task >= queue_size)
        current_task = 0;

    return run_queue[current_task];
}

uint32_t jroc_scheduler_ticks(void)
{
    return ticks;
}

uint32_t jroc_scheduler_queue_size(void)
{
    return queue_size;
}
