#include <stdint.h>

static int ready;

void jroc_syscall_init(void)
{
    ready = 1;
}

int jroc_syscall_status(void)
{
    return ready;
}

uint32_t jroc_syscall_dispatch(
    uint32_t number,
    uint32_t a,
    uint32_t b,
    uint32_t c,
    uint32_t d)
{
    (void)a;
    (void)b;
    (void)c;
    (void)d;

    if (!ready || number == 0)
        return 0xFFFFFFFFu;

    return number;
}
