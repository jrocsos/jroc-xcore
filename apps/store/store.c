static int ready = 0;

void jroc_store_app_init(void)
{
    ready = 1;
}

int jroc_store_app_status(void)
{
    return ready;
}
