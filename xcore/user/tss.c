static int tss_ready;

void jroc_tss_init(void)
{
    tss_ready = 1;
}

int jroc_tss_status(void)
{
    return tss_ready;
}
