#include <stdint.h>

#define JROC_MAX_WINDOWS 64

typedef struct
{
    uint32_t id;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
    uint8_t visible;
} jroc_window_t;

static jroc_window_t windows[JROC_MAX_WINDOWS];
static uint32_t next_window = 1;

void jroc_window_manager_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_WINDOWS; i++)
        windows[i].visible = 0;

    next_window = 1;
}

int jroc_window_create(
    int32_t x,
    int32_t y,
    uint32_t width,
    uint32_t height)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_WINDOWS; i++)
    {
        if (!windows[i].visible)
        {
            windows[i].id = next_window++;
            windows[i].x = x;
            windows[i].y = y;
            windows[i].width = width;
            windows[i].height = height;
            windows[i].visible = 1;

            return (int)windows[i].id;
        }
    }

    return -1;
}

int jroc_window_exists(uint32_t id)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_WINDOWS; i++)
    {
        if (windows[i].visible &&
            windows[i].id == id)
            return 1;
    }

    return 0;
}
