static int rollback_ready = 0;

void jroc_rollback_init(void)
{
    rollback_ready = 1;
}

int jroc_rollback_status(void)
{
    return rollback_ready;
}
