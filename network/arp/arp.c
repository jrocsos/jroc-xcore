#include <stdint.h>

#define JROC_ARP_TABLE_SIZE 32

typedef struct
{
    uint32_t ip;
    uint8_t mac[6];
    uint8_t valid;
} jroc_arp_entry_t;

static jroc_arp_entry_t table[JROC_ARP_TABLE_SIZE];

void jroc_arp_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_ARP_TABLE_SIZE; i++)
        table[i].valid = 0;
}

int jroc_arp_add(
    uint32_t ip,
    const uint8_t *mac)
{
    uint32_t i;

    if (!mac)
        return -1;

    for (i = 0; i < JROC_ARP_TABLE_SIZE; i++)
    {
        if (!table[i].valid)
        {
            uint32_t j;

            table[i].ip = ip;

            for (j = 0; j < 6; j++)
                table[i].mac[j] = mac[j];

            table[i].valid = 1;

            return 0;
        }
    }

    return -1;
}

int jroc_arp_find(
    uint32_t ip,
    uint8_t *mac)
{
    uint32_t i;

    if (!mac)
        return 0;

    for (i = 0; i < JROC_ARP_TABLE_SIZE; i++)
    {
        if (table[i].valid &&
            table[i].ip == ip)
        {
            uint32_t j;

            for (j = 0; j < 6; j++)
                mac[j] = table[i].mac[j];

            return 1;
        }
    }

    return 0;
}
