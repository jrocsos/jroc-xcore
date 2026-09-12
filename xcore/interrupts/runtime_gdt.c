#include <stdint.h>

struct jroc_gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

static struct jroc_gdt_entry gdt[3];

static void jroc_gdt_set(
    int index,
    uint32_t base,
    uint32_t limit,
    uint8_t access,
    uint8_t granularity)
{
    gdt[index].base_low = base & 0xFFFFu;
    gdt[index].base_middle = (base >> 16) & 0xFFu;
    gdt[index].base_high = (base >> 24) & 0xFFu;

    gdt[index].limit_low = limit & 0xFFFFu;
    gdt[index].granularity = (limit >> 16) & 0x0Fu;
    gdt[index].granularity |= granularity & 0xF0u;

    gdt[index].access = access;
}

void jroc_runtime_gdt_prepare(void)
{
    jroc_gdt_set(0, 0, 0, 0, 0);
    jroc_gdt_set(1, 0, 0xFFFFFFFFu, 0x9A, 0xCF);
    jroc_gdt_set(2, 0, 0xFFFFFFFFu, 0x92, 0xCF);
}
