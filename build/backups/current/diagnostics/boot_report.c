static int boot_report_ready;

void jroc_boot_report_init(void)
{
    boot_report_ready = 1;
}

int jroc_boot_report_status(void)
{
    return boot_report_ready;
}
