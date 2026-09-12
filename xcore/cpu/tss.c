#include <stdint.h>

typedef struct
{
    uint32_t prev_tss;

    uint32_t esp0;
    uint32_t ss0;

    uint32_t esp1;
    uint32_t ss1;

    uint32_t esp2;
    uint32_t ss2;

    uint32_t cr3;
    uint32_t eip;
    uint32_t eflags;

    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;

    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;

    uint32_t es;
    uint32_t cs;
    uint32_t ss;
    uint32_t ds;
    uint32_t fs;
    uint32_t gs;

    uint32_t ldt;
    uint16_t trap;
    uint16_t iomap;

} __attribute__((packed)) jroc_tss_t;

static jroc_tss_t tss;
static int ready = 0;

void jroc_tss_init(uint32_t kernel_stack, uint16_t kernel_ss)
{
    uint8_t *p = (uint8_t *)&tss;
    uint32_t i;

    for (i = 0; i < sizeof(tss); i++)
        p[i] = 0;

    tss.esp0 = kernel_stack;
    tss.ss0 = kernel_ss;
    tss.iomap = sizeof(tss);

    ready = 1;
}

int jroc_tss_status(void)
{
    return ready;
}

uint32_t jroc_tss_stack(void)
{
    return tss.esp0;
}
