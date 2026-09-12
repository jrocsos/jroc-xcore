static int release_manager_ready;

void jroc_release_manager_init(void)
{
    release_manager_ready = 1;
}

int jroc_release_manager_status(void)
{
    return release_manager_ready;
}
