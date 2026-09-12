static int ready = 0;

void xcore_ipc_init(void)
{
    ready = 1;
}

int xcore_ipc_status(void)
{
    return ready;
}
