#include <stdint.h>

enum
{
    JROC_PERMISSION_READ = 1,
    JROC_PERMISSION_WRITE = 2,
    JROC_PERMISSION_EXEC = 4,
    JROC_PERMISSION_NET = 8
};

static int policy_ready = 0;

void jroc_security_policy_init(void)
{
    policy_ready = 1;
}

int jroc_security_policy_status(void)
{
    return policy_ready;
}

int jroc_security_permission_allowed(
    uint32_t permissions,
    uint32_t requested)
{
    return (permissions & requested) == requested;
}
