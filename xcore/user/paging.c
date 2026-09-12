#include <stdint.h>

static int paging_ready;

void jroc_paging_init(void)
{
    paging_ready = 1;
}

int jroc_paging_status(void)
{
    return paging_ready;
}

uint32_t jroc_page_align(uint32_t address)
{
    return address & 0xFFFFF000u;
}
