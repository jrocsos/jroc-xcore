static int ready = 0;

void xcore_scheduler_api_init(void)
{
    ready = 1;
}

int xcore_scheduler_api_status(void)
{
    return ready;
}
