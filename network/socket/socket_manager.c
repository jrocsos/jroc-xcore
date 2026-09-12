#include <stdint.h>

#define JROC_SOCKET_MAX 64

typedef struct
{
    uint32_t id;
    uint16_t local_port;
    uint16_t remote_port;
    uint32_t remote_ip;
    uint8_t protocol;
    uint8_t state;
} jroc_socket_t;

static jroc_socket_t sockets[JROC_SOCKET_MAX];
static uint32_t next_id = 1;

void jroc_socket_manager_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
        sockets[i].id = 0;

    next_id = 1;
}

int jroc_socket_open(uint8_t protocol)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
    {
        if (sockets[i].id == 0)
        {
            sockets[i].id = next_id++;
            sockets[i].protocol = protocol;
            sockets[i].state = 1;

            return (int)sockets[i].id;
        }
    }

    return -1;
}

int jroc_socket_valid(uint32_t id)
{
    uint32_t i;

    for (i = 0; i < JROC_SOCKET_MAX; i++)
    {
        if (sockets[i].id == id)
            return 1;
    }

    return 0;
}
