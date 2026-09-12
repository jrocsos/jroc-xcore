static int ready;

void jroc_init_process(void)
{
    ready = 1;
}

int jroc_init_status(void)
{
    return ready;
}
