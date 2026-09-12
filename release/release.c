static int release_ready = 0;

void jroc_release_init(void)
{
    release_ready = 1;
}

int jroc_release_status(void)
{
    return release_ready;
}
