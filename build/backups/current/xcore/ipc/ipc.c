#include <stdint.h>

#define JROC_IPC_MAX 32

static uint32_t channels[JROC_IPC_MAX];
static uint32_t count;

void jroc_ipc_init(void)
{
    count = 0;
}

int jroc_ipc_create(void)
{
    if (count >= JROC_IPC_MAX)
        return -1;

    channels[count] = count + 1;
    count++;

    return (int)channels[count - 1];
}
