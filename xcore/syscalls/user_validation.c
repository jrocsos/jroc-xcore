#include <stdint.h>

#define USER_LOW  0x00400000u
#define USER_HIGH 0xC0000000u

int jroc_validate_user_range(
    uint32_t address,
    uint32_t length)
{
    uint32_t end;

    if (address < USER_LOW)
        return 0;

    if (length > USER_HIGH - address)
        return 0;

    end = address + length;

    if (end > USER_HIGH)
        return 0;

    return 1;
}
