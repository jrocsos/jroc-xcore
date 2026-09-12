#include <stdint.h>

enum {
    JROC_CORE = 1,
    JROC_MEMORY,
    JROC_INTERRUPTS,
    JROC_PROCESS,
    JROC_STORAGE,
    JROC_NETWORK,
    JROC_SECURITY,
    JROC_SERVICES,
    JROC_USERSPACE,
    JROC_DESKTOP,
    JROC_APPS,
    JROC_SDK,
    JROC_PACKAGES,
    JROC_AI,
    JROC_CLOUD,
    JROC_BACKEND,
    JROC_FRONTEND,
    JROC_DEVELOPER,
    JROC_RECOVERY
};

static uint32_t registered = 0;

void jroc_registry_init(void)
{
    registered = 1;
}

int jroc_registry_status(void)
{
    return registered;
}

uint32_t jroc_registry_version(void)
{
    return 0x00010000u;
}
