#include <stdint.h>

#define JROC_MAX_INODES 256

typedef struct
{
    uint32_t inode;
    uint32_t size;
    uint32_t blocks;
    uint16_t mode;
    uint16_t links;
    uint8_t active;
} jroc_inode_t;

static jroc_inode_t inodes[JROC_MAX_INODES];

void jroc_inode_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_INODES; i++)
        inodes[i].active = 0;

    inodes[0].inode = 1;
    inodes[0].mode = 0040755;
    inodes[0].links = 2;
    inodes[0].active = 1;
}

int jroc_inode_create(
    uint16_t mode)
{
    uint32_t i;

    for (i = 1; i < JROC_MAX_INODES; i++)
    {
        if (!inodes[i].active)
        {
            inodes[i].inode = i + 1;
            inodes[i].mode = mode;
            inodes[i].links = 1;
            inodes[i].size = 0;
            inodes[i].blocks = 0;
            inodes[i].active = 1;

            return (int)inodes[i].inode;
        }
    }

    return -1;
}

int jroc_inode_valid(uint32_t inode)
{
    if (inode == 0 || inode > JROC_MAX_INODES)
        return 0;

    return inodes[inode - 1].active != 0;
}
