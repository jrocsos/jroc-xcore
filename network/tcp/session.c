static int tcp_session_ready = 0;

void jroc_tcp_session_init(void)
{
    tcp_session_ready = 1;
}

int jroc_tcp_session_status(void)
{
    return tcp_session_ready;
}
