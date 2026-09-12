static int ready = 0;

void xcore_interrupt_api_init(void)
{
    ready = 1;
}

int xcore_interrupt_api_status(void)
{
    return ready;
}
