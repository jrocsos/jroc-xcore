#include <stdint.h>

typedef struct
{
    uint8_t destination[6];
    uint8_t source[6];
    uint16_t type;
} jroc_ethernet_header_t;

int jroc_ethernet_frame_size(void)
{
    return sizeof(jroc_ethernet_header_t);
}
