#include <stdint.h>

static uint32_t reads = 0;
static uint32_t writes = 0;

void jroc_block_io_init(void)
{
    reads = 0;
    writes = 0;
}

int jroc_block_read(
    uint32_t block,
    void *buffer)
{
    if (!buffer)
        return -1;

    (void)block;
    reads++;

    return 0;
}

int jroc_block_write(
    uint32_t block,
    const void *buffer)
{
    if (!buffer)
        return -1;

    (void)block;
    writes++;

    return 0;
}

uint32_t jroc_block_reads(void)
{
    return reads;
}

uint32_t jroc_block_writes(void)
{
    return writes;
}
