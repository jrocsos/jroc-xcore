static int wm_ready = 0;

void jroc_window_runtime_init(void)
{
    wm_ready = 1;
}

int jroc_window_runtime_status(void)
{
    return wm_ready;
}
