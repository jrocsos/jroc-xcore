static int ready = 0;

void xcore_security_init(void)
{
    ready = 1;
}

int xcore_security_status(void)
{
    return ready;
}
