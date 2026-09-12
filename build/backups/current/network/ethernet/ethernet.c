static int ready;

void jroc_ethernet_init(void) { ready = 1; }
int jroc_ethernet_status(void) { return ready; }
