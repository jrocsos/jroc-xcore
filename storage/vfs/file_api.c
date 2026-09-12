#include <stdint.h>

#define JROC_MAX_OPEN_FILES 64

typedef struct
{
    uint32_t handle;
    uint32_t inode;
    uint32_t offset;
    uint8_t mode;
    uint8_t active;
} jroc_open_file_t;

static jroc_open_file_t files[JROC_MAX_OPEN_FILES];
static uint32_t next_handle = 1;

void jroc_file_api_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
        files[i].active = 0;

    next_handle = 1;
}

int jroc_file_open(
    uint32_t inode,
    uint8_t mode)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
    {
        if (!files[i].active)
        {
            files[i].handle = next_handle++;
            files[i].inode = inode;
            files[i].offset = 0;
            files[i].mode = mode;
            files[i].active = 1;

            return (int)files[i].handle;
        }
    }

    return -1;
}

int jroc_file_valid(
    uint32_t handle)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_OPEN_FILES; i++)
    {
        if (files[i].active &&
            files[i].handle == handle)
            return 1;
    }

    return 0;
}
