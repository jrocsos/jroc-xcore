#include <stdint.h>

#define HEAP_START 0x01000000u
#define HEAP_SIZE  0x00100000u

static uint32_t heap_next = HEAP_START;

void xcore_allocator_init(void)
{
    heap_next = HEAP_START;
}

uint32_t xcore_alloc(uint32_t size)
{
    uint32_t aligned;

    if (!size)
        return 0;

    aligned = (size + 15u) & ~15u;

    if (heap_next + aligned > HEAP_START + HEAP_SIZE)
        return 0;

    uint32_t result = heap_next;
    heap_next += aligned;

    return result;
}
