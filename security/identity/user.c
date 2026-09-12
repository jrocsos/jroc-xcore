#include <stdint.h>

typedef struct
{
    uint32_t uid;
    uint32_t gid;
    uint8_t active;
} jroc_user_t;

static jroc_user_t root_user;
static int ready = 0;

void jroc_identity_runtime_init(void)
{
    root_user.uid = 0;
    root_user.gid = 0;
    root_user.active = 1;
    ready = 1;
}

int jroc_identity_runtime_status(void)
{
    return ready;
}
