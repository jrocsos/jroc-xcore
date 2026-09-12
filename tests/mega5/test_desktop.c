#include <assert.h>

void jroc_desktop_init(void);
int jroc_desktop_status(void);

void jroc_window_manager_init(void);
int jroc_window_create(
    int, int,
    unsigned int,
    unsigned int);
int jroc_window_exists(unsigned int);

int main(void)
{
    jroc_desktop_init();
    assert(jroc_desktop_status());

    jroc_window_manager_init();

    int id = jroc_window_create(
        10, 10, 640, 480);

    assert(id > 0);
    assert(jroc_window_exists((unsigned int)id));

    return 0;
}
