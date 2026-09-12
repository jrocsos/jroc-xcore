static int ready = 0;

void jroc_service_ipc_init(void)
{
    ready = 1;
}

int jroc_service_ipc_status(void)
{
    return ready;
}
