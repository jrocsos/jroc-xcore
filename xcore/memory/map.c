#include <stdint.h>

#define JROC_MAX_MAPPINGS 128

typedef struct
{
    uint32_t virtual_address;
    uint32_t physical_address;
    uint32_t flags;
    uint8_t active;
} jroc_mapping_t;

static jroc_mapping_t mappings[JROC_MAX_MAPPINGS];

void jroc_mapping_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_MAPPINGS; i++)
        mappings[i].active = 0;
}

int jroc_map_page(
    uint32_t virtual_address,
    uint32_t physical_address,
    uint32_t flags)
{
    uint32_t i;

    virtual_address &= 0xFFFFF000u;
    physical_address &= 0xFFFFF000u;

    for (i = 0; i < JROC_MAX_MAPPINGS; i++)
    {
        if (!mappings[i].active)
        {
            mappings[i].virtual_address = virtual_address;
            mappings[i].physical_address = physical_address;
            mappings[i].flags = flags;
            mappings[i].active = 1;

            return 0;
        }
    }

    return -1;
}

int jroc_mapping_find(
    uint32_t virtual_address,
    uint32_t *physical_address)
{
    uint32_t i;

    virtual_address &= 0xFFFFF000u;

    for (i = 0; i < JROC_MAX_MAPPINGS; i++)
    {
        if (mappings[i].active &&
            mappings[i].virtual_address == virtual_address)
        {
            if (physical_address)
                *physical_address =
                    mappings[i].physical_address;

            return 1;
        }
    }

    return 0;
}
