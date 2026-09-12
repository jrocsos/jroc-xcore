static int settings_ready = 0;

void jroc_settings_init(void)
{
    settings_ready = 1;
}

int jroc_settings_status(void)
{
    return settings_ready;
}
