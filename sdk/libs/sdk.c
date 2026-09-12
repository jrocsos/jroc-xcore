static int ready = 0;

void jroc_sdk_init(void)
{
    ready = 1;
}

int jroc_sdk_status(void)
{
    return ready;
}
