#include <assert.h>

void jroc_frontend_init(void);
int jroc_frontend_status(void);

void jroc_navigation_init(void);
void jroc_navigation_set(unsigned int);
unsigned int jroc_navigation_get(void);

int main(void)
{
    jroc_frontend_init();

    assert(jroc_frontend_status());

    jroc_navigation_init();
    jroc_navigation_set(7);

    assert(jroc_navigation_get() == 7);

    return 0;
}
