#include <assert.h>

int jroc_user_range_valid(
    unsigned int,
    unsigned int);

int main(void)
{
    assert(jroc_user_range_valid(
        0x00400000u, 4096u));

    assert(!jroc_user_range_valid(
        0x00001000u, 4096u));

    assert(!jroc_user_range_valid(
        0xC0000000u, 1u));

    return 0;
}
