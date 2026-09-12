static int ready = 0;

void xcore_boot_manager_init(void)
{
    ready = 1;
}

int xcore_boot_manager_status(void)
{
    return ready;
}
