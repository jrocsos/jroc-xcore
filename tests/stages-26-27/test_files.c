#include <assert.h>

void jroc_file_api_init(void);
int jroc_file_open(
    unsigned int,
    unsigned char);
int jroc_file_valid(unsigned int);

int main(void)
{
    jroc_file_api_init();

    int fd = jroc_file_open(1, 3);

    assert(fd > 0);
    assert(jroc_file_valid(fd));

    return 0;
}
