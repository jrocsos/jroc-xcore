#include <stdint.h>

static int desktop_ready = 0;

void jroc_desktop_init(void)
{
    desktop_ready = 1;
}

int jroc_desktop_status(void)
{
    return desktop_ready;
}

uint32_t jroc_desktop_version(void)
{
    return 5;
}
