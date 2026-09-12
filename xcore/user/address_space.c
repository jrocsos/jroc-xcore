#include <stdint.h>

static uint32_t next_space = 1;

uint32_t jroc_address_space_create(void)
{
    return next_space++;
}
