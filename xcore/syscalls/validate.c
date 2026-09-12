#include <stdint.h>

#define USER_BASE 0x00400000u
#define USER_TOP  0xC0000000u

int jroc_user_range_valid(
    uint32_t address,
    uint32_t length)
{
    if (address < USER_BASE)
        return 0;

    if (address >= USER_TOP)
        return 0;

    if (length > USER_TOP - address)
        return 0;

    if (address + length > USER_TOP)
        return 0;

    return 1;
}
