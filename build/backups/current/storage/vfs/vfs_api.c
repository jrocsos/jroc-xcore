static int ready = 0;

void jroc_vfs_api_init(void)
{
    ready = 1;
}

int jroc_vfs_api_status(void)
{
    return ready;
}
