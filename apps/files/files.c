static int ready = 0;

void jroc_files_app_init(void)
{
    ready = 1;
}

int jroc_files_app_status(void)
{
    return ready;
}
