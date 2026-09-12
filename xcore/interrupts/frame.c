#include <stdint.h>
#include "frame.h"

static volatile uint32_t frames_seen = 0;

void jroc_interrupt_frame_init(void)
{
    frames_seen = 0;
}

void jroc_interrupt_frame_seen(void)
{
    frames_seen++;
}

uint32_t jroc_interrupt_frame_count(void)
{
    return frames_seen;
}

int jroc_interrupt_from_user(
    const jroc_interrupt_frame_t *frame)
{
    if (!frame)
        return 0;

    return (frame->cs & 3u) == 3u;
}
