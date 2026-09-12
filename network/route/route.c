#include <stdint.h>

#define JROC_MAX_ROUTES 32

typedef struct
{
    uint32_t destination;
    uint32_t gateway;
    uint32_t mask;
    uint32_t interface_id;
    uint8_t active;
} jroc_route_t;

static jroc_route_t routes[JROC_MAX_ROUTES];

void jroc_route_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_ROUTES; i++)
        routes[i].active = 0;
}

int jroc_route_add(
    uint32_t destination,
    uint32_t gateway,
    uint32_t mask,
    uint32_t interface_id)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_ROUTES; i++)
    {
        if (!routes[i].active)
        {
            routes[i].destination = destination;
            routes[i].gateway = gateway;
            routes[i].mask = mask;
            routes[i].interface_id = interface_id;
            routes[i].active = 1;

            return 0;
        }
    }

    return -1;
}

int jroc_route_count(void)
{
    int count = 0;
    uint32_t i;

    for (i = 0; i < JROC_MAX_ROUTES; i++)
        if (routes[i].active)
            count++;

    return count;
}
