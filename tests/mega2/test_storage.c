#include <assert.h>

void jroc_block_device_init(unsigned int);
int jroc_block_device_online(void);

void jroc_superblock_init(unsigned int);
int jroc_superblock_valid(void);

void jroc_inode_init(void);
int jroc_inode_create(unsigned short);
int jroc_inode_valid(unsigned int);

int main(void)
{
    jroc_block_device_init(2048);
    assert(jroc_block_device_online());

    jroc_superblock_init(2048);
    assert(jroc_superblock_valid());

    jroc_inode_init();

    int inode = jroc_inode_create(0100644);

    assert(inode > 0);
    assert(jroc_inode_valid(inode));

    return 0;
}
