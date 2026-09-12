#include <stdint.h>

#define JROC_PACKET_SIZE 2048

typedef struct
{
    uint32_t length;
    uint8_t data[JROC_PACKET_SIZE];
} jroc_packet_t;

static jroc_packet_t packet;

void jroc_packet_init(void)
{
    uint32_t i;

    packet.length = 0;

    for (i = 0; i < JROC_PACKET_SIZE; i++)
        packet.data[i] = 0;
}

uint32_t jroc_packet_capacity(void)
{
    return JROC_PACKET_SIZE;
}
