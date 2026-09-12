#include <assert.h>
#include <stdint.h>

void jroc_net_device_init(void);
int jroc_net_device_status(void);

void jroc_socket_init(void);
int jroc_socket_create(uint8_t);
int jroc_socket_exists(uint32_t);

void jroc_route_init(void);
int jroc_route_add(
    uint32_t,
    uint32_t,
    uint32_t,
    uint32_t);
int jroc_route_count(void);

void jroc_arp_init(void);
int jroc_arp_add(
    uint32_t,
    const uint8_t *);
int jroc_arp_find(
    uint32_t,
    uint8_t *);

int main(void)
{
    jroc_net_device_init();
    assert(jroc_net_device_status());

    jroc_socket_init();

    int socket_id = jroc_socket_create(6);

    assert(socket_id > 0);
    assert(jroc_socket_exists(socket_id));

    jroc_route_init();

    assert(
        jroc_route_add(
            0,
            0,
            0,
            1) == 0);

    assert(jroc_route_count() == 1);

    jroc_arp_init();

    const uint8_t mac[6] =
        { 1, 2, 3, 4, 5, 6 };

    assert(jroc_arp_add(
        0x01020304u,
        mac) == 0);

    uint8_t result[6];

    assert(jroc_arp_find(
        0x01020304u,
        result));

    return 0;
}
