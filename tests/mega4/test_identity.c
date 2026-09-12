#include <assert.h>

void jroc_identity_init(void);

int jroc_user_create(
    unsigned int);

int jroc_user_exists(
    unsigned int);

int main(void)
{
    jroc_identity_init();

    int uid = jroc_user_create(100);

    assert(uid > 0);
    assert(jroc_user_exists(uid));

    return 0;
}
