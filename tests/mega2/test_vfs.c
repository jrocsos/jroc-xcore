#include <assert.h>

void jroc_vfs_init(void);
int jroc_vfs_mount(unsigned int, unsigned int);
void jroc_open_file_init(void);
int jroc_open(unsigned int, unsigned char);
int jroc_fd_valid(unsigned int);

int main(void)
{
    jroc_vfs_init();

    assert(jroc_vfs_mount(1, 1) > 0);

    jroc_open_file_init();

    int fd = jroc_open(1, 3);

    assert(fd >= 3);
    assert(jroc_fd_valid(fd));

    return 0;
}
