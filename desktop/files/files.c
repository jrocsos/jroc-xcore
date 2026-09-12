static int file_manager_ready = 0;

void jroc_file_manager_init(void)
{
    file_manager_ready = 1;
}

int jroc_file_manager_status(void)
{
    return file_manager_ready;
}
