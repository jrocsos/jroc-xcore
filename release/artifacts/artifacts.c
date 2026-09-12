static int artifacts_ready = 0;

void jroc_artifacts_init(void)
{
    artifacts_ready = 1;
}

int jroc_artifacts_status(void)
{
    return artifacts_ready;
}
