static int udp_ready = 0;

void jroc_udp_state_init(void)
{
    udp_ready = 1;
}

int jroc_udp_state_status(void)
{
    return udp_ready;
}
