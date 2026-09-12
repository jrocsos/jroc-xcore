#include <stdint.h>

#define JROC_PLATFORM_API 0x00010000u

uint32_t jroc_platform_api_version(void)
{
    return JROC_PLATFORM_API;
}

int jroc_platform_api_status(void)
{
    return 1;
}
