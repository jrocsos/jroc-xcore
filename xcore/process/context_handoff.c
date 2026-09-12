#include <stdint.h>

static uint32_t current_pid = 0;
static uint32_t next_pid = 0;

void jroc_context_handoff_init(void)
{
    current_pid = 0;
    next_pid = 0;
}

void jroc_context_handoff_set(
    uint32_t current,
    uint32_t next)
{
    current_pid = current;
    next_pid = next;
}

uint32_t jroc_context_current(void)
{
    return current_pid;
}

uint32_t jroc_context_next(void)
{
    return next_pid;
}

int jroc_context_switch_required(void)
{
    return current_pid != next_pid;
}
