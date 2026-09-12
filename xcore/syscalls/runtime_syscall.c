#include <stdint.h>

#define JROC_MAX_SYSCALLS 64

static uint32_t handlers[JROC_MAX_SYSCALLS];

void jroc_runtime_syscall_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SYSCALLS; i++)
        handlers[i] = 0;
}

int jroc_runtime_syscall_register(
    uint32_t number,
    uint32_t handler)
{
    if (number >= JROC_MAX_SYSCALLS)
        return -1;

    handlers[number] = handler;

    return 0;
}

uint32_t jroc_runtime_syscall_get(
    uint32_t number)
{
    if (number >= JROC_MAX_SYSCALLS)
        return 0;

    return handlers[number];
}

int jroc_runtime_user_pointer_valid(
    uint32_t address,
    uint32_t length)
{
    const uint32_t low = 0x00400000u;
    const uint32_t high = 0xC0000000u;

    if (address < low)
        return 0;

    if (address >= high)
        return 0;

    if (length > high - address)
        return 0;

    return address + length <= high;
}
