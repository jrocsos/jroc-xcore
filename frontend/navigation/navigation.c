#include <stdint.h>

static uint32_t current_view = 0;

void jroc_navigation_init(void)
{
    current_view = 0;
}

void jroc_navigation_set(uint32_t view)
{
    current_view = view;
}

uint32_t jroc_navigation_get(void)
{
    return current_view;
}
