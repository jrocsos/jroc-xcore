static int gui_ready = 0;

void jroc_gui_runtime_init(void)
{
    gui_ready = 1;
}

int jroc_gui_runtime_status(void)
{
    return gui_ready;
}
