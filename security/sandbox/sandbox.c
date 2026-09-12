#include <stdint.h>

typedef struct
{
    uint32_t pid;
    uint32_t allowed_flags;
    uint8_t active;
} jroc_sandbox_t;

static jroc_sandbox_t sandbox;

void jroc_sandbox_init(void)
{
    sandbox.pid = 0;
    sandbox.allowed_flags = 0;
    sandbox.active = 0;
}

int jroc_sandbox_create(
    uint32_t pid,
    uint32_t flags)
{
    sandbox.pid = pid;
    sandbox.allowed_flags = flags;
    sandbox.active = 1;

    return 0;
}

int jroc_sandbox_allows(
    uint32_t pid,
    uint32_t operation)
{
    if (!sandbox.active)
        return 0;

    if (sandbox.pid != pid)
        return 0;

    return (sandbox.allowed_flags & operation) == operation;
}
