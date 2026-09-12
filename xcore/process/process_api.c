static int ready = 0;

void xcore_process_api_init(void)
{
    ready = 1;
}

int xcore_process_api_status(void)
{
    return ready;
}
