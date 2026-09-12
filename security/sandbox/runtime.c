static int sandbox_ready = 0;

void jroc_sandbox_runtime_init(void)
{
    sandbox_ready = 1;
}

int jroc_sandbox_runtime_status(void)
{
    return sandbox_ready;
}
