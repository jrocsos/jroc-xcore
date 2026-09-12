#include <stdint.h>

struct jroc_idt_entry
{
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

static struct jroc_idt_entry idt[256];

void jroc_runtime_idt_prepare(void)
{
    uint32_t i;

    for (i = 0; i < 256; i++)
    {
        idt[i].base_low = 0;
        idt[i].selector = 0x08;
        idt[i].zero = 0;
        idt[i].flags = 0x8E;
        idt[i].base_high = 0;
    }
}
