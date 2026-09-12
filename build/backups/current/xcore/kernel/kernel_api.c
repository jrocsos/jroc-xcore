static int ready = 0;

void xcore_kernel_api_init(void)
{
    ready = 1;
}

int xcore_kernel_api_status(void)
{
    return ready;
}
