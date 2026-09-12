static int link_ready = 0;

void jroc_network_link_init(void)
{
    link_ready = 1;
}

int jroc_network_link_status(void)
{
    return link_ready;
}
