static int ready;

void jroc_tcp_init(void) { ready = 1; }
int jroc_tcp_status(void) { return ready; }
