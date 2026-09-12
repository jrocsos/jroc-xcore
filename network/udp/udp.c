#include <stdint.h>

typedef struct
{
    uint16_t source_port;
    uint16_t destination_port;
    uint16_t length;
    uint16_t checksum;
} jroc_udp_header_t;

int jroc_udp_header_size(void)
{
    return sizeof(jroc_udp_header_t);
}
