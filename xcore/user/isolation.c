static int isolation_ready = 0;

void jroc_process_isolation_init(void)
{
    isolation_ready = 1;
}

int jroc_process_isolation_status(void)
{
    return isolation_ready;
}

int jroc_process_can_access_kernel(void)
{
    return 0;
}
