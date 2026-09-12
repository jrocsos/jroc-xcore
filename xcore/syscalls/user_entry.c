#include <stdint.h>

static int entry_ready = 0;

void jroc_syscall_user_entry_init(void)
{
    entry_ready = 1;
}

int jroc_syscall_user_entry_status(void)
{
    return entry_ready;
}

uint32_t jroc_syscall_validate_user_pointer(uint32_t address)
{
    /*
     * Basic lower-user-space validation boundary.
     * A full MMU/page-table validation layer belongs to the
     * complete address-space implementation.
     */
    if (address < 0x00400000u)
        return 0;

    if (address >= 0xC0000000u)
        return 0;

    return 1;
}
