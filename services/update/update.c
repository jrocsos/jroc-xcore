static int update_ready = 0;

void jroc_update_init(void)
{
    update_ready = 1;
}

int jroc_update_status(void)
{
    return update_ready;
}
