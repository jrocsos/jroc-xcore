#include <stdint.h>

#define JROC_API_MAJOR 1
#define JROC_API_MINOR 0

uint32_t jroc_api_version(void)
{
    return (JROC_API_MAJOR << 16) | JROC_API_MINOR;
}

int jroc_api_ready(void)
{
    return 1;
}
