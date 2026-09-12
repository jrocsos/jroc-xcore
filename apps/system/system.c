static int ready = 0;

void jroc_system_app_init(void)
{
    ready = 1;
}

int jroc_system_app_status(void)
{
    return ready;
}
