static int ready = 0;

void jroc_terminal_app_init(void)
{
    ready = 1;
}

int jroc_terminal_app_status(void)
{
    return ready;
}
