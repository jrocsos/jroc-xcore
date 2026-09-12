static int theme_ready = 0;

void jroc_theme_init(void)
{
    theme_ready = 1;
}

int jroc_theme_status(void)
{
    return theme_ready;
}
