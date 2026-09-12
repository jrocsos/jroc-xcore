#include <stdint.h>

static int ready = 0;

void jroc_dns_init(void)
{
    ready = 1;
}

int jroc_dns_status(void)
{
    return ready;
}

uint16_t jroc_dns_port(void)
{
    return 53;
}
