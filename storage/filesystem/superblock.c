#include <stdint.h>

typedef struct
{
    uint32_t magic;
    uint32_t block_size;
    uint32_t total_blocks;
    uint32_t free_blocks;
    uint32_t root_inode;
} jroc_superblock_t;

#define JROC_FS_MAGIC 0x4A524F43u

static jroc_superblock_t superblock;
static int ready = 0;

void jroc_superblock_init(
    uint32_t total_blocks)
{
    superblock.magic = JROC_FS_MAGIC;
    superblock.block_size = 512;
    superblock.total_blocks = total_blocks;
    superblock.free_blocks = total_blocks;
    superblock.root_inode = 1;

    ready = 1;
}

int jroc_superblock_valid(void)
{
    return ready &&
           superblock.magic == JROC_FS_MAGIC;
}

uint32_t jroc_superblock_blocks(void)
{
    return superblock.total_blocks;
}
