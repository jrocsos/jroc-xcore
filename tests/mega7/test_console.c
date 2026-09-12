#include <assert.h>

void jroc_runtime_console_init(void);
int jroc_runtime_console_put(char);

const char *jroc_runtime_console_text(void);

int main(void)
{
    jroc_runtime_console_init();

    assert(jroc_runtime_console_put('J') == 0);
    assert(jroc_runtime_console_put('R') == 0);
    assert(jroc_runtime_console_put('O') == 0);
    assert(jroc_runtime_console_put('C') == 0);

    const char *text =
        jroc_runtime_console_text();

    assert(text[0] == 'J');
    assert(text[1] == 'R');
    assert(text[2] == 'O');
    assert(text[3] == 'C');

    return 0;
}
