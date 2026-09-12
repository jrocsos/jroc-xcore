static int ready = 0;

void jroc_about_app_init(void)
{
    ready = 1;
}

int jroc_about_app_status(void)
{
    return ready;
}
