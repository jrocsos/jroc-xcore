#include <stdint.h>

#define JROC_HEAP_START 0x01000000u
#define JROC_HEAP_END   0x02000000u

static uint32_t heap_pointer = JROC_HEAP_START;

void jroc_heap_init(void)
{
    heap_pointer = JROC_HEAP_START;
}

uint32_t jroc_heap_alloc(uint32_t size)
{
    uint32_t aligned;

    if (size == 0)
        return 0;

    aligned = (size + 15u) & ~15u;

    if (heap_pointer > JROC_HEAP_END - aligned)
        return 0;

    uint32_t result = heap_pointer;
    heap_pointer += aligned;

    return result;
}

uint32_t jroc_heap_used(void)
{
    return heap_pointer - JROC_HEAP_START;
}
