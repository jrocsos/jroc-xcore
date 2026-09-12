static int input_ready = 0;

void jroc_desktop_input_init(void)
{
    input_ready = 1;
}

int jroc_desktop_input_status(void)
{
    return input_ready;
}
