#include <stdint.h>
#include "frame.h"

typedef void (*jroc_interrupt_handler_t)(
    jroc_interrupt_frame_t *
);

static jroc_interrupt_handler_t handlers[256];

void jroc_interrupt_dispatch_init(void)
{
    uint32_t i;

    for (i = 0; i < 256; i++)
        handlers[i] = 0;
}

int jroc_interrupt_register(
    uint32_t number,
    jroc_interrupt_handler_t handler)
{
    if (number >= 256 || !handler)
        return -1;

    handlers[number] = handler;
    return 0;
}

void jroc_interrupt_dispatch(
    jroc_interrupt_frame_t *frame)
{
    if (!frame)
        return;

    jroc_interrupt_frame_seen();

    if (frame->interrupt_number < 256 &&
        handlers[frame->interrupt_number])
    {
        handlers[frame->interrupt_number](frame);
    }
}
