#include <stdint.h>

typedef struct
{
    uint8_t version_ihl;
    uint8_t tos;
    uint16_t length;
    uint16_t identification;
    uint16_t flags_fragment;
    uint8_t ttl;
    uint8_t protocol;
    uint16_t checksum;
    uint32_t source;
    uint32_t destination;
} jroc_ipv4_header_t;

int jroc_ipv4_header_size(void)
{
    return sizeof(jroc_ipv4_header_t);
}
