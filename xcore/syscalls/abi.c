#include <stdint.h>

enum {
    JROC_SYS_WRITE = 1,
    JROC_SYS_READ,
    JROC_SYS_OPEN,
    JROC_SYS_CLOSE,
    JROC_SYS_ALLOC,
    JROC_SYS_FREE,
    JROC_SYS_SPAWN,
    JROC_SYS_EXIT,
    JROC_SYS_SLEEP,
    JROC_SYS_TIME
};

uint32_t jroc_syscall_total(void)
{
    return 10;
}
