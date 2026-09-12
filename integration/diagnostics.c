static int diagnostics_ready = 0;

void jroc_diagnostics_init(void)
{
    diagnostics_ready = 1;
}

int jroc_diagnostics_status(void)
{
    return diagnostics_ready;
}
