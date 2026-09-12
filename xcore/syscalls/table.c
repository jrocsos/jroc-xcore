#include <stdint.h>

#define JROC_SYSCALL_MAX 64

static uint32_t handlers[JROC_SYSCALL_MAX];

void jroc_syscall_table_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_SYSCALL_MAX; i++)
        handlers[i] = 0;
}

int jroc_syscall_register(
    uint32_t number,
    uint32_t handler)
{
    if (number >= JROC_SYSCALL_MAX)
        return -1;

    handlers[number] = handler;

    return 0;
}

uint32_t jroc_syscall_handler(
    uint32_t number)
{
    if (number >= JROC_SYSCALL_MAX)
        return 0;

    return handlers[number];
}
