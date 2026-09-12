#include <stdint.h>

static int ready = 0;

void jroc_privilege_init(void)
{
    ready = 1;
}

int jroc_privilege_status(void)
{
    return ready;
}

int jroc_is_user_selector(uint16_t selector)
{
    return (selector & 3u) == 3u;
}

int jroc_is_kernel_selector(uint16_t selector)
{
    return (selector & 3u) == 0u;
}
