#include <stdint.h>

#define MESSAGE_SIZE 128

typedef struct
{
    uint32_t sender;
    uint32_t receiver;
    uint32_t length;
    uint8_t data[MESSAGE_SIZE];
} jroc_message_t;

static jroc_message_t last_message;
static int message_ready = 0;

void jroc_message_init(void)
{
    uint32_t i;

    last_message.sender = 0;
    last_message.receiver = 0;
    last_message.length = 0;

    for (i = 0; i < MESSAGE_SIZE; i++)
        last_message.data[i] = 0;

    message_ready = 0;
}

int jroc_message_send(
    uint32_t sender,
    uint32_t receiver,
    const void *data,
    uint32_t length)
{
    const uint8_t *src;
    uint32_t i;

    if (!data || length > MESSAGE_SIZE)
        return -1;

    src = (const uint8_t *)data;

    last_message.sender = sender;
    last_message.receiver = receiver;
    last_message.length = length;

    for (i = 0; i < length; i++)
        last_message.data[i] = src[i];

    message_ready = 1;

    return 0;
}

int jroc_message_available(void)
{
    return message_ready;
}
