#include <stdint.h>

typedef struct
{
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;

    uint32_t eip;
    uint32_t eflags;

    uint32_t cs;
    uint32_t ss;
} jroc_cpu_context_t;

void jroc_context_clear(jroc_cpu_context_t *context)
{
    uint8_t *p = (uint8_t *)context;
    uint32_t i;

    for (i = 0; i < sizeof(jroc_cpu_context_t); i++)
        p[i] = 0;
}
