static int rings_ready = 0;

void jroc_rings_init(void)
{
    rings_ready = 1;
}

int jroc_rings_status(void)
{
    return rings_ready;
}

int jroc_user_segment(uint16_t selector)
{
    return (selector & 3) == 3;
}
