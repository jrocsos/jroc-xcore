#include <assert.h>

int jroc_is_user_selector(unsigned short);
int jroc_is_kernel_selector(unsigned short);

int main(void)
{
    assert(jroc_is_user_selector(0x1B));
    assert(jroc_is_user_selector(0x23));

    assert(jroc_is_kernel_selector(0x08));
    assert(jroc_is_kernel_selector(0x10));

    return 0;
}
