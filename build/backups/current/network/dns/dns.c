static int ready;

void jroc_dns_init(void) { ready = 1; }
int jroc_dns_status(void) { return ready; }
