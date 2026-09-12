#include <stdint.h>

typedef struct
{
    uint32_t code;
    uint32_t healthy;
} jroc_health_t;

static jroc_health_t health;

void jroc_health_init(void)
{
    health.code = 0;
    health.healthy = 1;
}

void jroc_health_failure(uint32_t code)
{
    health.code = code;
    health.healthy = 0;
}

int jroc_health_ok(void)
{
    return health.healthy != 0;
}

uint32_t jroc_health_code(void)
{
    return health.code;
}
