static int ready = 0;

void xcore_syscall_api_init(void)
{
    ready = 1;
}

int xcore_syscall_api_status(void)
{
    return ready;
}
