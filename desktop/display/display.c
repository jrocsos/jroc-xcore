#include <stdint.h>

typedef struct
{
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint8_t active;
} jroc_display_t;

static jroc_display_t display;

void jroc_display_init(
    uint32_t width,
    uint32_t height,
    uint32_t depth)
{
    display.width = width;
    display.height = height;
    display.depth = depth;
    display.active = 1;
}

uint32_t jroc_display_width(void)
{
    return display.width;
}

uint32_t jroc_display_height(void)
{
    return display.height;
}

int jroc_display_status(void)
{
    return display.active;
}
