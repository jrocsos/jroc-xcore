#include <stdint.h>

#define JROC_MAX_PARTITIONS 16

typedef struct
{
    uint32_t id;
    uint32_t start_block;
    uint32_t block_count;
    uint8_t type;
    uint8_t active;
} jroc_partition_t;

static jroc_partition_t partitions[JROC_MAX_PARTITIONS];
static uint32_t count = 0;

void jroc_partition_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PARTITIONS; i++)
        partitions[i].active = 0;

    count = 0;
}

int jroc_partition_create(
    uint32_t start_block,
    uint32_t block_count,
    uint8_t type)
{
    if (count >= JROC_MAX_PARTITIONS)
        return -1;

    partitions[count].id = count + 1;
    partitions[count].start_block = start_block;
    partitions[count].block_count = block_count;
    partitions[count].type = type;
    partitions[count].active = 1;

    count++;

    return (int)partitions[count - 1].id;
}

uint32_t jroc_partition_count(void)
{
    return count;
}
