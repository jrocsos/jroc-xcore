#include <stdint.h>

#define JROC_MAX_USERS 32

typedef struct
{
    uint32_t uid;
    uint32_t gid;
    uint8_t active;
} jroc_user_t;

static jroc_user_t users[JROC_MAX_USERS];
static uint32_t next_uid = 0;

void jroc_identity_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_USERS; i++)
        users[i].active = 0;

    users[0].uid = 0;
    users[0].gid = 0;
    users[0].active = 1;

    next_uid = 1;
}

int jroc_user_create(uint32_t gid)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_USERS; i++)
    {
        if (!users[i].active)
        {
            users[i].uid = next_uid++;
            users[i].gid = gid;
            users[i].active = 1;

            return (int)users[i].uid;
        }
    }

    return -1;
}

int jroc_user_exists(uint32_t uid)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_USERS; i++)
    {
        if (users[i].active &&
            users[i].uid == uid)
            return 1;
    }

    return 0;
}
