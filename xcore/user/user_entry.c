#include <stdint.h>

typedef struct
{
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
    uint32_t esp;
    uint32_t ss;
} jroc_user_entry_frame_t;

static int ready = 0;

void jroc_user_entry_init(void)
{
    ready = 1;
}

int jroc_user_entry_status(void)
{
    return ready;
}

int jroc_user_entry_validate(
    const jroc_user_entry_frame_t *frame)
{
    if (!frame)
        return 0;

    if ((frame->cs & 3u) != 3u)
        return 0;

    if ((frame->ss & 3u) != 3u)
        return 0;

    return 1;
}
