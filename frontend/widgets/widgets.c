static int widgets_ready = 0;

void jroc_widgets_init(void)
{
    widgets_ready = 1;
}

int jroc_widgets_status(void)
{
    return widgets_ready;
}
