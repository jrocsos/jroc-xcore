enum
{
    JROC_TCP_CLOSED = 0,
    JROC_TCP_LISTEN,
    JROC_TCP_SYN_SENT,
    JROC_TCP_SYN_RECEIVED,
    JROC_TCP_ESTABLISHED,
    JROC_TCP_FIN_WAIT
};

static int ready = 0;

void jroc_tcp_init(void)
{
    ready = 1;
}

int jroc_tcp_status(void)
{
    return ready;
}
