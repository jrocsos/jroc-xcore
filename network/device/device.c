#include <stdint.h>

typedef struct
{
    uint32_t id;
    uint32_t mtu;
    uint8_t mac[6];
    uint8_t up;
} jroc_net_device_t;

static jroc_net_device_t device;
static int ready = 0;

void jroc_net_device_init(void)
{
    device.id = 1;
    device.mtu = 1500;
    device.up = 1;

    device.mac[0] = 0x02;
    device.mac[1] = 0x4A;
    device.mac[2] = 0x52;
    device.mac[3] = 0x4F;
    device.mac[4] = 0x43;
    device.mac[5] = 0x01;

    ready = 1;
}

int jroc_net_device_status(void)
{
    return ready;
}

uint32_t jroc_net_device_mtu(void)
{
    return device.mtu;
}
