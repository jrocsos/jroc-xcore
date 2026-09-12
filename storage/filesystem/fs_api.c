#include <stdint.h>

typedef struct
{
    uint32_t inode;
    uint32_t size;
    uint32_t flags;
} jroc_file_info_t;

static int fs_ready = 0;

void jroc_fs_api_init(void)
{
    fs_ready = 1;
}

int jroc_fs_api_status(void)
{
    return fs_ready;
}

int jroc_fs_stat(uint32_t inode, jroc_file_info_t *info)
{
    if (!info || !fs_ready)
        return -1;

    info->inode = inode;
    info->size = 0;
    info->flags = 0;

    return 0;
}
