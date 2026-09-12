static int checks_ready = 0;

void jroc_release_checks_init(void)
{
    checks_ready = 1;
}

int jroc_release_checks_status(void)
{
    return checks_ready;
}
