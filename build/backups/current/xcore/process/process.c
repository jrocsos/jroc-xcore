#include <stdint.h>

#define MAX_PROCESSES 64

struct process {
    uint32_t pid;
    uint8_t state;
};

static struct process table[MAX_PROCESSES];
static uint32_t next_pid = 1;

void xcore_process_init(void)
{
    int i;

    for (i = 0; i < MAX_PROCESSES; i++) {
        table[i].pid = 0;
        table[i].state = 0;
    }

    next_pid = 1;
}

int xcore_process_create(void)
{
    int i;

    for (i = 0; i < MAX_PROCESSES; i++) {
        if (table[i].state == 0) {
            table[i].pid = next_pid++;
            table[i].state = 1;
            return (int)table[i].pid;
        }
    }

    return -1;
}

int xcore_process_count(void)
{
    int count = 0;
    int i;

    for (i = 0; i < MAX_PROCESSES; i++)
        if (table[i].state)
            count++;

    return count;
}
