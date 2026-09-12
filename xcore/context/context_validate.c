#include <stdint.h>
#include "context.h"

int jroc_context_valid(const jroc_cpu_context_t *ctx)
{
    if (ctx == 0)
        return 0;

    /*
     * Basic sanity checks.
     * Full segment/address validation belongs to the protected-mode stage.
     */
    if (ctx->cs == 0)
        return 0;

    return 1;
}
