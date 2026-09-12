#include <stdint.h>

struct idt_entry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

static struct idt_entry idt[256];
static struct idt_ptr idtr;

void xcore_idt_init(void)
{
    int i;

    for (i = 0; i < 256; i++) {
        idt[i].base_low = 0;
        idt[i].selector = 0x08;
        idt[i].zero = 0;
        idt[i].flags = 0x8E;
        idt[i].base_high = 0;
    }

    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint32_t)&idt;

    __asm__ volatile("lidtl %0" : : "m"(idtr));
}
