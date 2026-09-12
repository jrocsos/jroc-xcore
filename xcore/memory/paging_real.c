#include <stdint.h>

#define PAGE_PRESENT 0x001
#define PAGE_RW      0x002
#define PAGE_USER    0x004

static uint32_t page_directory[1024] __attribute__((aligned(4096)));
static uint32_t page_tables[1024][1024] __attribute__((aligned(4096)));

static int paging_enabled = 0;

void xcore_paging_real_init(void)
{
    uint32_t i;
    uint32_t j;

    for (i = 0; i < 1024; i++)
        page_directory[i] = 0;

    /*
     * Identity-map the first 4 MiB.
     * This is the first safe paging region for the kernel.
     */
    for (j = 0; j < 1024; j++)
    {
        page_tables[0][j] =
            (j * 0x1000u) |
            PAGE_PRESENT |
            PAGE_RW;
    }

    page_directory[0] =
        ((uint32_t)&page_tables[0]) |
        PAGE_PRESENT |
        PAGE_RW;

    __asm__ volatile(
        "mov %0, %%cr3"
        :
        : "r"((uint32_t)&page_directory)
    );

    uint32_t cr0;

    __asm__ volatile(
        "mov %%cr0, %0"
        : "=r"(cr0)
    );

    cr0 |= 0x80000000u;

    __asm__ volatile(
        "mov %0, %%cr0"
        :
        : "r"(cr0)
    );

    paging_enabled = 1;
}

int xcore_paging_real_status(void)
{
    return paging_enabled;
}
