#include <stdint.h>

int jroc_runtime_selector_is_user(
    uint16_t selector)
{
    return (selector & 3u) == 3u;
}

int jroc_runtime_selector_is_kernel(
    uint16_t selector)
{
    return (selector & 3u) == 0u;
}
