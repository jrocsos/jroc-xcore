static int ready;

void jroc_udp_init(void) { ready = 1; }
int jroc_udp_status(void) { return ready; }
