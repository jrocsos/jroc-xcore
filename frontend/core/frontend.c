static int frontend_ready = 0;

void jroc_frontend_init(void)
{
    frontend_ready = 1;
}

int jroc_frontend_status(void)
{
    return frontend_ready;
}
