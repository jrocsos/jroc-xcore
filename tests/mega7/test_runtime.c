#include <assert.h>

void jroc_runtime_reset(void);
void jroc_runtime_boot(void);

void jroc_runtime_set_core(int);
void jroc_runtime_set_security(int);
void jroc_runtime_set_services(int);
void jroc_runtime_set_storage(int);
void jroc_runtime_set_network(int);
void jroc_runtime_set_userspace(int);
void jroc_runtime_set_desktop(int);

int jroc_runtime_ready(void);
int jroc_runtime_full_stack_ready(void);

int main(void)
{
    jroc_runtime_reset();

    assert(!jroc_runtime_ready());

    jroc_runtime_boot();
    jroc_runtime_set_core(1);

    assert(jroc_runtime_ready());

    jroc_runtime_set_security(1);
    jroc_runtime_set_services(1);
    jroc_runtime_set_storage(1);
    jroc_runtime_set_network(1);
    jroc_runtime_set_userspace(1);
    jroc_runtime_set_desktop(1);

    assert(jroc_runtime_full_stack_ready());

    return 0;
}
