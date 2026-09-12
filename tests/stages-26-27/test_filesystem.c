#include <assert.h>

void jroc_superblock_init(unsigned int);
int jroc_superblock_valid(void);
unsigned int jroc_superblock_blocks(void);

int main(void)
{
    jroc_superblock_init(1024);

    assert(jroc_superblock_valid());
    assert(jroc_superblock_blocks() == 1024);

    return 0;
}
