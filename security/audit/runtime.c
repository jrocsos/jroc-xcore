#include <stdint.h>

static uint32_t audit_events = 0;

void jroc_audit_runtime_init(void)
{
    audit_events = 0;
}

void jroc_audit_runtime_event(void)
{
    audit_events++;
}

uint32_t jroc_audit_runtime_count(void)
{
    return audit_events;
}
