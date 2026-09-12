#include <stdint.h>

typedef enum
{
    JROC_TASK_EMPTY = 0,
    JROC_TASK_READY = 1,
    JROC_TASK_RUNNING = 2,
    JROC_TASK_BLOCKED = 3
} jroc_task_state_t;

typedef struct
{
    uint32_t pid;
    uint32_t stack_base;
    uint32_t stack_size;
    uint32_t context_address;
    jroc_task_state_t state;
} jroc_task_context_t;

static jroc_task_context_t tasks[64];

void jroc_task_context_init(void)
{
    uint32_t i;

    for (i = 0; i < 64; i++)
    {
        tasks[i].pid = 0;
        tasks[i].stack_base = 0;
        tasks[i].stack_size = 0;
        tasks[i].context_address = 0;
        tasks[i].state = JROC_TASK_EMPTY;
    }
}

int jroc_task_context_create(
    uint32_t pid,
    uint32_t stack_base,
    uint32_t stack_size,
    uint32_t context_address)
{
    uint32_t i;

    for (i = 0; i < 64; i++)
    {
        if (tasks[i].state == JROC_TASK_EMPTY)
        {
            tasks[i].pid = pid;
            tasks[i].stack_base = stack_base;
            tasks[i].stack_size = stack_size;
            tasks[i].context_address = context_address;
            tasks[i].state = JROC_TASK_READY;

            return 0;
        }
    }

    return -1;
}

int jroc_task_context_count(void)
{
    int count = 0;
    uint32_t i;

    for (i = 0; i < 64; i++)
    {
        if (tasks[i].state != JROC_TASK_EMPTY)
            count++;
    }

    return count;
}
