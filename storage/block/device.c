#include <stdint.h>

#define JROC_BLOCK_SIZE 512u

static int ready = 0;
static uint32_t block_count = 0;

void jroc_block_device_init(
    uint32_t blocks)
{
    block_count = blocks;
    ready = 1;
}

int jroc_block_device_status(void)
{
    return ready;
}

uint32_t jroc_block_count(void)
{
    return block_count;
}

uint32_t jroc_block_size(void)
{
    return JROC_BLOCK_SIZE;
}
