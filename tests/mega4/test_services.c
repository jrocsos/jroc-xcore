#include <assert.h>

void jroc_service_manager_init(void);

int jroc_service_register(
    unsigned int);

int jroc_service_running(
    unsigned int);

int main(void)
{
    jroc_service_manager_init();

    int service =
        jroc_service_register(1);

    assert(service > 0);
    assert(jroc_service_running(service));

    return 0;
}
