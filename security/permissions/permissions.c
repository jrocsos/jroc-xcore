#include <stdint.h>

#define JROC_PERM_READ  1u
#define JROC_PERM_WRITE 2u
#define JROC_PERM_EXEC  4u
#define JROC_PERM_NET   8u

int jroc_permission_allowed(
    uint32_t granted,
    uint32_t requested)
{
    return (granted & requested) == requested;
}

uint32_t jroc_default_user_permissions(void)
{
    return JROC_PERM_READ | JROC_PERM_EXEC;
}

uint32_t jroc_default_service_permissions(void)
{
    return JROC_PERM_READ |
           JROC_PERM_WRITE |
           JROC_PERM_EXEC |
           JROC_PERM_NET;
}
