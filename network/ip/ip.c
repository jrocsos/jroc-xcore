static int ready;

void jroc_ip_init(void) { ready = 1; }
int jroc_ip_status(void) { return ready; }
