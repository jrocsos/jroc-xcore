static int ready;

void jroc_services_init(void) { ready = 1; }
int jroc_services_status(void) { return ready; }
