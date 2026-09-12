#include <stdint.h>

#define JROC_MAX_OPEN_FILES 128

typedef struct
{
    uint32_t fd;
    uint32_t inode;
    uint32_t offset;
    uint8_t mode;
    uint8_t active;
} jroc_open_file_t;

static jroc_open_file_t files[JROC_MAX_OPEN_FILES];
static uint32_t next_fd = 3;

void jroc_open_file_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
        files[i].active = 0;

    next_fd = 3;
}

int jroc_open(
    uint32_t inode,
    uint8_t mode)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
    {
        if (!files[i].active)
        {
            files[i].fd = next_fd++;
            files[i].inode = inode;
            files[i].offset = 0;
            files[i].mode = mode;
            files[i].active = 1;

            return (int)files[i].fd;
        }
    }

    return -1;
}

int jroc_fd_valid(uint32_t fd)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
    {
        if (files[i].active &&
            files[i].fd == fd)
            return 1;
    }

    return 0;
}
