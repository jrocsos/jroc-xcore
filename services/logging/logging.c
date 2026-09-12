#include <stdint.h>

static uint32_t events = 0;

void jroc_logging_init(void)
{
    events = 0;
}

void jroc_log_event(uint32_t event)
{
    (void)event;
    events++;
}

uint32_t jroc_log_count(void)
{
    return events;
}
