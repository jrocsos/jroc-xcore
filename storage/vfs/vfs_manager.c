#include <stdint.h>

#define JROC_MAX_MOUNTS 16

typedef struct
{
    uint32_t id;
    uint32_t device;
    uint32_t root_inode;
    uint8_t active;
} jroc_mount_t;

static jroc_mount_t mounts[JROC_MAX_MOUNTS];
static uint32_t mount_count = 0;

void jroc_vfs_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_MOUNTS; i++)
        mounts[i].active = 0;

    mount_count = 0;
}

int jroc_vfs_mount(
    uint32_t device,
    uint32_t root_inode)
{
    if (mount_count >= JROC_MAX_MOUNTS)
        return -1;

    mounts[mount_count].id = mount_count + 1;
    mounts[mount_count].device = device;
    mounts[mount_count].root_inode = root_inode;
    mounts[mount_count].active = 1;

    mount_count++;

    return (int)mounts[mount_count - 1].id;
}

uint32_t jroc_vfs_mount_count(void)
{
    return mount_count;
}
