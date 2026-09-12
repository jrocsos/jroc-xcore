#define MAX_DEVICES 64

static int device_count = 0;

void xcore_device_init(void)
{
    device_count = 0;
}

int xcore_device_register(void)
{
    if (device_count >= MAX_DEVICES)
        return -1;

    return ++device_count;
}

int xcore_device_count(void)
{
    return device_count;
}
