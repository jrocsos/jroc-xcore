#include <stdint.h>

#define JROC_MAX_NOTIFICATIONS 32

static uint32_t count = 0;

void jroc_notifications_init(void)
{
    count = 0;
}

void jroc_notify(uint32_t type)
{
    (void)type;

    if (count < JROC_MAX_NOTIFICATIONS)
        count++;
}

uint32_t jroc_notification_count(void)
{
    return count;
}
