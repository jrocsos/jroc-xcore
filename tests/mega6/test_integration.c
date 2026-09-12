#include <assert.h>

void jroc_system_init(void);
int jroc_system_initialized(void);

int main(void)
{
    assert(!jroc_system_initialized());

    jroc_system_init();

    assert(jroc_system_initialized());

    /*
     * Calling twice must not reinitialize the system.
     */
    jroc_system_init();

    assert(jroc_system_initialized());

    return 0;
}
