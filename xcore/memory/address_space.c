#include <stdint.h>

#define JROC_MAX_SPACES 64
#define JROC_PAGE_SIZE 4096u

typedef struct
{
    uint32_t id;
    uint32_t page_directory;
    uint32_t user_start;
    uint32_t user_end;
    uint8_t active;
} jroc_address_space_t;

static jroc_address_space_t spaces[JROC_MAX_SPACES];
static uint32_t next_space_id = 1;

void jroc_address_space_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SPACES; i++)
        spaces[i].active = 0;

    next_space_id = 1;
}

int jroc_address_space_create(
    uint32_t page_directory)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SPACES; i++)
    {
        if (!spaces[i].active)
        {
            spaces[i].id = next_space_id++;
            spaces[i].page_directory = page_directory;
            spaces[i].user_start = 0x00400000u;
            spaces[i].user_end = 0xBFFFFFFFu;
            spaces[i].active = 1;

            return (int)spaces[i].id;
        }
    }

    return -1;
}

int jroc_address_space_valid(
    uint32_t id)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SPACES; i++)
    {
        if (spaces[i].active &&
            spaces[i].id == id)
            return 1;
    }

    return 0;
}

int jroc_address_valid(
    uint32_t id,
    uint32_t address,
    uint32_t length)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SPACES; i++)
    {
        if (spaces[i].active &&
            spaces[i].id == id)
        {
            if (address < spaces[i].user_start)
                return 0;

            if (length > spaces[i].user_end - address + 1u)
                return 0;

            if (address + length > spaces[i].user_end + 1u)
                return 0;

            return 1;
        }
    }

    return 0;
}
