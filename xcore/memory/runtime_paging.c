#include <stdint.h>

#define PAGE_PRESENT 0x001u
#define PAGE_WRITE   0x002u

static uint32_t page_directory[1024]
    __attribute__((aligned(4096)));

static uint32_t first_page_table[1024]
    __attribute__((aligned(4096)));

static int paging_ready = 0;

void jroc_runtime_paging_prepare(void)
{
    uint32_t i;

    for (i = 0; i < 1024; i++)
    {
        first_page_table[i] =
            (i * 0x1000u) |
            PAGE_PRESENT |
            PAGE_WRITE;

        page_directory[i] = 0;
    }

    page_directory[0] =
        ((uint32_t)first_page_table) |
        PAGE_PRESENT |
        PAGE_WRITE;

    paging_ready = 1;
}

int jroc_runtime_paging_status(void)
{
    return paging_ready;
}

uint32_t jroc_runtime_page_directory(void)
{
    return (uint32_t)page_directory;
}
