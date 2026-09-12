static int ready = 0;

void jroc_shell_init(void)
{
    ready = 1;
}

int jroc_shell_status(void)
{
    return ready;
}
