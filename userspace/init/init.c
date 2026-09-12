static int ready = 0;
static int pid = 1;

void jroc_userspace_init(void)
{
    ready = 1;
    pid = 1;
}

int jroc_userspace_status(void)
{
    return ready;
}

int jroc_init_pid(void)
{
    return pid;
}
