#include <stdint.h>

#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002

typedef struct {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
} multiboot_info_t;

static uint32_t detected_memory_kb = 640;

void xcore_memory_detect(uint32_t magic, uint32_t info_addr)
{
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC || info_addr == 0)
        return;

    multiboot_info_t *info = (multiboot_info_t*)info_addr;

    if (info->flags & 1u)
        detected_memory_kb = info->mem_lower + info->mem_upper + 1024u;
}

uint32_t xcore_memory_kb(void)
{
    return detected_memory_kb;
}
