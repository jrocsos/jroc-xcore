#include <stdint.h>

#define JROC_SOCKET_MAX 64

enum
{
    JROC_SOCKET_CLOSED = 0,
    JROC_SOCKET_OPEN = 1,
    JROC_SOCKET_LISTEN = 2,
    JROC_SOCKET_CONNECTED = 3
};

typedef struct
{
    uint32_t id;
    uint32_t local_ip;
    uint32_t remote_ip;
    uint16_t local_port;
    uint16_t remote_port;
    uint8_t protocol;
    uint8_t state;
} jroc_socket_t;

static jroc_socket_t sockets[JROC_SOCKET_MAX];
static uint32_t next_id = 1;

void jroc_socket_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
        sockets[i].state = JROC_SOCKET_CLOSED;

    next_id = 1;
}

int jroc_socket_create(uint8_t protocol)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
    {
        if (sockets[i].state == JROC_SOCKET_CLOSED)
        {
            sockets[i].id = next_id++;
            sockets[i].protocol = protocol;
            sockets[i].state = JROC_SOCKET_OPEN;

            return (int)sockets[i].id;
        }
    }

    return -1;
}

int jroc_socket_exists(uint32_t id)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
        if (sockets[i].id == id &&
            sockets[i].state != JROC_SOCKET_CLOSED)
            return 1;

    return 0;
}
