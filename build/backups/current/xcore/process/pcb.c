#include <stdint.h>

#define JROC_MAX_PROCESSES 64

typedef enum {
    JROC_EMPTY = 0,
    JROC_READY,
    JROC_RUNNING,
    JROC_BLOCKED,
    JROC_ZOMBIE
} jroc_state_t;

typedef struct {
    uint32_t pid;
    uint32_t parent;
    uint32_t eip;
    uint32_t esp;
    uint32_t page_directory;
    uint8_t privilege;
    jroc_state_t state;
} jroc_pcb_t;

static jroc_pcb_t table[JROC_MAX_PROCESSES];
static uint32_t next_pid = 1;

void jroc_process_init(void)
{
    int i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        table[i].state = JROC_EMPTY;

    next_pid = 1;
}

int jroc_process_create(uint32_t parent, uint8_t privilege)
{
    int i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
    {
        if (table[i].state == JROC_EMPTY)
        {
            table[i].pid = next_pid++;
            table[i].parent = parent;
            table[i].privilege = privilege;
            table[i].state = JROC_READY;
            return (int)table[i].pid;
        }
    }

    return -1;
}

int jroc_process_count(void)
{
    int n = 0;
    int i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        if (table[i].state != JROC_EMPTY)
            n++;

    return n;
}
