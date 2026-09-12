#include <stdint.h>
#include "context.h"

void jroc_context_clear(
    jroc_cpu_context_t *ctx)
{
    uint32_t *p;
    uint32_t i;

    if (!ctx)
        return;

    p = (uint32_t *)ctx;

    for (i = 0;
         i < sizeof(jroc_cpu_context_t) / sizeof(uint32_t);
         i++)
    {
        p[i] = 0;
    }

    ctx->eflags = 0x202;
}
