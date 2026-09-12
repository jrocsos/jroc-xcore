#include <stdint.h>

typedef struct
{
    uint32_t disk_id;
    uint32_t size_mb;
    uint8_t online;
} jroc_disk_t;

static jroc_disk_t disk;

void jroc_disk_init(uint32_t size_mb)
{
    disk.disk_id = 1;
    disk.size_mb = size_mb;
    disk.online = 1;
}

int jroc_disk_online(void)
{
    return disk.online;
}

uint32_t jroc_disk_size_mb(void)
{
    return disk.size_mb;
}
