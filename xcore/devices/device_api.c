static int ready = 0;

void xcore_device_api_init(void)
{
    ready = 1;
}

int xcore_device_api_status(void)
{
    return ready;
}
