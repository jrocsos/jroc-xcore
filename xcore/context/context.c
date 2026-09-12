#include <stdint.h>

typedef struct {
    uint32_t edi, esi, ebp, esp;
    uint32_t ebx, edx, ecx, eax;
    uint32_t eip, eflags;
    uint32_t cs, ss;
} jroc_context_t;

void jroc_context_clear(jroc_context_t *ctx)
{
    uint8_t *p = (uint8_t *)ctx;
    uint32_t i;

    for (i = 0; i < sizeof(jroc_context_t); i++)
        p[i] = 0;
}
