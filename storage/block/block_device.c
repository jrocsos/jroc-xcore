#include <stdint.h>

#define JROC_BLOCK_SIZE 512u

typedef struct
{
    uint32_t id;
    uint32_t blocks;
    uint32_t block_size;
    uint8_t online;
} jroc_block_device_t;

static jroc_block_device_t device;

void jroc_block_device_init(uint32_t blocks)
{
    device.id = 1;
    device.blocks = blocks;
    device.block_size = JROC_BLOCK_SIZE;
    device.online = 1;
}

int jroc_block_device_online(void)
{
    return device.online;
}

uint32_t jroc_block_device_blocks(void)
{
    return device.blocks;
}

uint32_t jroc_block_device_size(void)
{
    return device.block_size;
}
