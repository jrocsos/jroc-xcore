#include <stdint.h>

static int auth_ready = 0;

void jroc_auth_init(void)
{
    auth_ready = 1;
}

int jroc_auth_status(void)
{
    return auth_ready;
}

int jroc_authenticate_user(
    uint32_t uid,
    uint32_t credential_token)
{
    if (!auth_ready)
        return 0;

    if (uid == 0 && credential_token != 0)
        return 1;

    return credential_token != 0;
}
