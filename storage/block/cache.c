#include <stdint.h>

#define JROC_BLOCK_SIZE 512
#define JROC_CACHE_BLOCKS 16

typedef struct
{
    uint32_t block;
    uint8_t valid;
    uint8_t data[JROC_BLOCK_SIZE];
} jroc_cache_entry_t;

static jroc_cache_entry_t cache[JROC_CACHE_BLOCKS];

void jroc_block_cache_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_CACHE_BLOCKS; i++)
    {
        cache[i].block = 0;
        cache[i].valid = 0;
    }
}

int jroc_block_cache_status(void)
{
    return 1;
}
