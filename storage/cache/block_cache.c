#include <stdint.h>

#define JROC_CACHE_ENTRIES 32
#define JROC_CACHE_BLOCK 512

typedef struct
{
    uint32_t block;
    uint8_t valid;
    uint8_t dirty;
    uint8_t data[JROC_CACHE_BLOCK];
} jroc_cache_entry_t;

static jroc_cache_entry_t cache[JROC_CACHE_ENTRIES];

void jroc_cache_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_CACHE_ENTRIES; i++)
    {
        cache[i].block = 0;
        cache[i].valid = 0;
        cache[i].dirty = 0;
    }
}

int jroc_cache_status(void)
{
    return 1;
}
