static int ready = 0;

void jroc_disk_api_init(void)
{
    ready = 1;
}

int jroc_disk_api_status(void)
{
    return ready;
}
