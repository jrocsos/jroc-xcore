#include <stdint.h>

#define MAX_CHANNELS 32

typedef struct
{
    uint32_t id;
    uint32_t owner;
    uint32_t receiver;
    uint8_t active;
} jroc_channel_t;

static jroc_channel_t channels[MAX_CHANNELS];
static uint32_t next_channel = 1;

void jroc_ipc_init(void)
{
    uint32_t i;

    for (i = 0; i < MAX_CHANNELS; i++)
        channels[i].active = 0;

    next_channel = 1;
}

int jroc_ipc_channel_create(
    uint32_t owner,
    uint32_t receiver)
{
    uint32_t i;

    for (i = 0; i < MAX_CHANNELS; i++)
    {
        if (!channels[i].active)
        {
            channels[i].id = next_channel++;
            channels[i].owner = owner;
            channels[i].receiver = receiver;
            channels[i].active = 1;

            return (int)channels[i].id;
        }
    }

    return -1;
}

int jroc_ipc_channel_valid(
    uint32_t id)
{
    uint32_t i;

    for (i = 0; i < MAX_CHANNELS; i++)
    {
        if (channels[i].active &&
            channels[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}
