#define MAX_DEVICES 64

static int count = 0;

void xcore_device_manager_init(void)
{
    count = 0;
}

int xcore_device_register(void)
{
    if (count >= MAX_DEVICES)
        return -1;

    return ++count;
}

int xcore_device_count(void)
{
    return count;
}
