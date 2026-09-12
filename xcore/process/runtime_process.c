#include <stdint.h>

#define JROC_MAX_PROCESSES 64

enum
{
    JROC_PROCESS_FREE = 0,
    JROC_PROCESS_READY = 1,
    JROC_PROCESS_RUNNING = 2,
    JROC_PROCESS_BLOCKED = 3,
    JROC_PROCESS_ZOMBIE = 4
};

typedef struct
{
    uint32_t pid;
    uint32_t parent_pid;
    uint32_t entry;
    uint32_t stack;
    uint32_t address_space;
    uint8_t privilege;
    uint8_t state;
} jroc_runtime_process_t;

static jroc_runtime_process_t table[JROC_MAX_PROCESSES];
static uint32_t next_pid = 1;

void jroc_runtime_process_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        table[i].state = JROC_PROCESS_FREE;

    next_pid = 1;
}

int jroc_runtime_process_create(
    uint32_t parent_pid,
    uint32_t entry,
    uint32_t stack,
    uint32_t address_space,
    uint8_t privilege)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
    {
        if (table[i].state == JROC_PROCESS_FREE)
        {
            table[i].pid = next_pid++;
            table[i].parent_pid = parent_pid;
            table[i].entry = entry;
            table[i].stack = stack;
            table[i].address_space = address_space;
            table[i].privilege = privilege;
            table[i].state = JROC_PROCESS_READY;

            return (int)table[i].pid;
        }
    }

    return -1;
}

int jroc_runtime_process_count(void)
{
    int count = 0;
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        if (table[i].state != JROC_PROCESS_FREE)
            count++;

    return count;
}
