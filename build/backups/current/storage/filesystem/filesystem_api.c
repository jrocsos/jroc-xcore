static int ready = 0;

void jroc_filesystem_api_init(void)
{
    ready = 1;
}

int jroc_filesystem_api_status(void)
{
    return ready;
}
