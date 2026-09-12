#include <stdint.h>

typedef struct
{
    uint32_t destination;
    uint32_t gateway;
    uint32_t mask;
    uint32_t interface_id;
} jroc_route_t;

static jroc_route_t default_route;
static int route_ready = 0;

void jroc_route_init(void)
{
    default_route.destination = 0;
    default_route.gateway = 0;
    default_route.mask = 0;
    default_route.interface_id = 0;

    route_ready = 1;
}

int jroc_route_status(void)
{
    return route_ready;
}
