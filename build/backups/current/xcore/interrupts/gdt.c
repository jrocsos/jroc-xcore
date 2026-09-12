#include <stdint.h>

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

static struct gdt_entry gdt[3];
static struct gdt_ptr gp;

static void set_gate(
    int n,
    uint32_t base,
    uint32_t limit,
    uint8_t access,
    uint8_t granularity)
{
    gdt[n].base_low = base & 0xFFFF;
    gdt[n].base_middle = (base >> 16) & 0xFF;
    gdt[n].base_high = (base >> 24) & 0xFF;

    gdt[n].limit_low = limit & 0xFFFF;
    gdt[n].granularity = (limit >> 16) & 0x0F;
    gdt[n].granularity |= granularity & 0xF0;

    gdt[n].access = access;
}

void xcore_gdt_init(void)
{
    gp.limit = sizeof(gdt) - 1;
    gp.base = (uint32_t)&gdt;

    set_gate(0, 0, 0, 0, 0);
    set_gate(1, 0, 0xFFFFFFFFu, 0x9A, 0xCF);
    set_gate(2, 0, 0xFFFFFFFFu, 0x92, 0xCF);

    /*
     * This module is compile-checked in the mega build.
     * Runtime activation is integrated separately to protect
     * the known-good boot path.
     */
    __asm__ volatile("lgdt %0" : : "m"(gp));
}
