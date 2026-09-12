#include <stdint.h>

static uint32_t frequency = 100;

void jroc_runtime_pit_set_frequency(
    uint32_t hz)
{
    if (hz)
        frequency = hz;
}

uint32_t jroc_runtime_pit_frequency(void)
{
    return frequency;
}
