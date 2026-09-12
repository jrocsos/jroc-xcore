#define JROC_MAX_MOUNTS 16

static int mounts[JROC_MAX_MOUNTS];
static int mount_count = 0;

void jroc_mount_init(void)
{
    int i;

    for (i = 0; i < JROC_MAX_MOUNTS; i++)
        mounts[i] = 0;

    mount_count = 0;
}

int jroc_mount_root(void)
{
    if (mount_count >= JROC_MAX_MOUNTS)
        return -1;

    mounts[mount_count++] = 1;
    return 0;
}

int jroc_mount_count(void)
{
    return mount_count;
}
