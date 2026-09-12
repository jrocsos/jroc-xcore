#include <stdint.h>

#define JROC_CONSOLE_BUFFER 256

static char buffer[JROC_CONSOLE_BUFFER];
static uint32_t length = 0;

void jroc_runtime_console_init(void)
{
    uint32_t i;

    length = 0;

    for (i = 0; i < JROC_CONSOLE_BUFFER; i++)
        buffer[i] = 0;
}

void jroc_runtime_console_reset(void)
{
    length = 0;
}

int jroc_runtime_console_put(char c)
{
    if (length >= JROC_CONSOLE_BUFFER - 1)
        return -1;

    buffer[length++] = c;
    buffer[length] = 0;

    return 0;
}

const char *jroc_runtime_console_text(void)
{
    return buffer;
}

uint32_t jroc_runtime_console_length(void)
{
    return length;
}
