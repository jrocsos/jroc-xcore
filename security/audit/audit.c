#include <stdint.h>

#define JROC_AUDIT_MAX 256

static uint32_t events[JROC_AUDIT_MAX];
static uint32_t count = 0;

void jroc_audit_init(void)
{
    count = 0;
}

void jroc_audit_event(uint32_t event)
{
    if (count < JROC_AUDIT_MAX)
        events[count++] = event;
}

uint32_t jroc_audit_count(void)
{
    return count;
}
