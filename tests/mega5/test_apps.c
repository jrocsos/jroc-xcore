#include <assert.h>

void jroc_terminal_app_init(void);
int jroc_terminal_app_status(void);

void jroc_files_app_init(void);
int jroc_files_app_status(void);

void jroc_settings_app_init(void);
int jroc_settings_app_status(void);

int main(void)
{
    jroc_terminal_app_init();
    jroc_files_app_init();
    jroc_settings_app_init();

    assert(jroc_terminal_app_status());
    assert(jroc_files_app_status());
    assert(jroc_settings_app_status());

    return 0;
}
