#include <stdint.h>

#define FRAME_SIZE 4096u
#define FRAME_COUNT 1024u

static uint8_t frames[FRAME_COUNT];

void xcore_frame_allocator_init(void)
{
    uint32_t i;

    for (i = 0; i < FRAME_COUNT; i++)
        frames[i] = 0;
}

uint32_t xcore_frame_alloc(void)
{
    uint32_t i;

    for (i = 0; i < FRAME_COUNT; i++)
    {
        if (!frames[i])
        {
            frames[i] = 1;
            return i * FRAME_SIZE;
        }
    }

    return 0;
}

void xcore_frame_free(uint32_t address)
{
    uint32_t index = address / FRAME_SIZE;

    if (index < FRAME_COUNT)
        frames[index] = 0;
}
