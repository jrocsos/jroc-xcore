#include <stdint.h>

typedef struct
{
    uint32_t service_id;
    uint32_t status;
} jroc_userspace_service_info_t;

void jroc_userspace_service_init(
    jroc_userspace_service_info_t *info,
    uint32_t service_id)
{
    if (!info)
        return;

    info->service_id = service_id;
    info->status = 1;
}
