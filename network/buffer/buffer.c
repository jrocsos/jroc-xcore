#include <stdint.h>

#define JROC_PACKET_BUFFER 2048

static uint8_t packet_buffer[JROC_PACKET_BUFFER];

void jroc_packet_buffer_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_PACKET_BUFFER; i++)
        packet_buffer[i] = 0;
}

uint32_t jroc_packet_buffer_size(void)
{
    return JROC_PACKET_BUFFER;
}
