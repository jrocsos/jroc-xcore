static int ready = 0;

void xcore_memory_api_init(void)
{
    ready = 1;
}

int xcore_memory_api_status(void)
{
    return ready;
}
