static int disk_api_ready = 0;

void jroc_disk_device_init(void)
{
    disk_api_ready = 1;
}

int jroc_disk_device_status(void)
{
    return disk_api_ready;
}
