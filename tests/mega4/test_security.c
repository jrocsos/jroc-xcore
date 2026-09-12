#include <assert.h>

int jroc_permission_allowed(
    unsigned int,
    unsigned int);

int main(void)
{
    assert(jroc_permission_allowed(15, 9));
    assert(!jroc_permission_allowed(1, 2));

    return 0;
}
