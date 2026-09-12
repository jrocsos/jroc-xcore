#include <stdint.h>

typedef struct
{
    uint8_t destination[6];
    uint8_t source[6];
    uint16_t type;
} jroc_eth_header_t;

int jroc_eth_header_size(void)
{
    return sizeof(jroc_eth_header_t);
}
