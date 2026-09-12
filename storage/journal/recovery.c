static int recovery_ready = 0;

void jroc_storage_recovery_init(void)
{
    recovery_ready = 1;
}

int jroc_storage_recovery_status(void)
{
    return recovery_ready;
}
