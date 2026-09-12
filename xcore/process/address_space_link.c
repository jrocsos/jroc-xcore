#include <stdint.h>

typedef struct
{
    uint32_t pid;
    uint32_t address_space;
    uint32_t page_directory;
    uint8_t active;
} jroc_process_space_t;

static jroc_process_space_t process_space;

void jroc_process_space_init(void)
{
    process_space.pid = 0;
    process_space.address_space = 0;
    process_space.page_directory = 0;
    process_space.active = 0;
}

int jroc_process_space_attach(
    uint32_t pid,
    uint32_t address_space,
    uint32_t page_directory)
{
    process_space.pid = pid;
    process_space.address_space = address_space;
    process_space.page_directory = page_directory;
    process_space.active = 1;

    return 0;
}

int jroc_process_space_status(void)
{
    return process_space.active;
}
