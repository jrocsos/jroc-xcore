#include <assert.h>

void jroc_fs_api_init(void);
int jroc_fs_api_status(void);

int main(void)
{
    jroc_fs_api_init();

    assert(jroc_fs_api_status() == 1);

    return 0;
}
