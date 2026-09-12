static int ready = 0;

void xcore_syscall_init(void)
{
    ready = 1;
}

int xcore_syscall_status(void)
{
    return ready;
}
