enum
{
    JROC_TCP_CLOSED = 0,
    JROC_TCP_LISTEN = 1,
    JROC_TCP_SYN_SENT = 2,
    JROC_TCP_SYN_RECEIVED = 3,
    JROC_TCP_ESTABLISHED = 4,
    JROC_TCP_FIN_WAIT = 5
};

static int tcp_ready = 0;

void jroc_tcp_state_init(void)
{
    tcp_ready = 1;
}

int jroc_tcp_state_status(void)
{
    return tcp_ready;
}
