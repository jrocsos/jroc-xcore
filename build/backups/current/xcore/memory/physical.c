#include <stdint.h>

#define MULTIBOOT_MAGIC 0x2BADB002u

struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
};

static uint32_t memory_kb = 640;

void xcore_memory_detect(uint32_t magic, uint32_t info_addr)
{
    if (magic != MULTIBOOT_MAGIC || info_addr == 0)
        return;

    struct multiboot_info *info =
        (struct multiboot_info *)info_addr;

    if (info->flags & 1u)
        memory_kb =
            info->mem_lower + info->mem_upper + 1024u;
}

uint32_t xcore_memory_kb(void)
{
    return memory_kb;
}
