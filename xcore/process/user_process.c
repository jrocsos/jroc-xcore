#include <stdint.h>

typedef struct
{
    uint32_t pid;
    uint32_t entry;
    uint32_t user_stack;
    uint32_t page_directory;

    uint16_t code_selector;
    uint16_t data_selector;

    uint8_t privilege;
    uint8_t state;

} jroc_user_process_t;

static jroc_user_process_t process;

void jroc_user_process_init(void)
{
    process.pid = 0;
    process.entry = 0;
    process.user_stack = 0;
    process.page_directory = 0;
    process.code_selector = 0x1B;
    process.data_selector = 0x23;
    process.privilege = 3;
    process.state = 0;
}

int jroc_user_process_configure(
    uint32_t pid,
    uint32_t entry,
    uint32_t stack,
    uint32_t page_directory)
{
    process.pid = pid;
    process.entry = entry;
    process.user_stack = stack;
    process.page_directory = page_directory;
    process.state = 1;

    return 0;
}

int jroc_user_process_status(void)
{
    return process.state;
}
