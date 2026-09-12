#include <stdint.h>

#define JROC_MAX_SERVICES 64

typedef struct
{
    uint32_t id;
    uint32_t owner;
    uint8_t state;
} jroc_service_t;

static jroc_service_t services[JROC_MAX_SERVICES];
static uint32_t next_id = 1;

void jroc_service_manager_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SERVICES; i++)
        services[i].state = 0;

    next_id = 1;
}

int jroc_service_register(uint32_t owner)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SERVICES; i++)
    {
        if (!services[i].state)
        {
            services[i].id = next_id++;
            services[i].owner = owner;
            services[i].state = 1;

            return (int)services[i].id;
        }
    }

    return -1;
}

int jroc_service_running(uint32_t id)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SERVICES; i++)
    {
        if (services[i].state &&
            services[i].id == id)
            return 1;
    }

    return 0;
}
