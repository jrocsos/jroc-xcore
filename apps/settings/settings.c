static int ready = 0;

void jroc_settings_app_init(void)
{
    ready = 1;
}

int jroc_settings_app_status(void)
{
    return ready;
}
