static int ready;

void jroc_net_device_init(void) { ready = 1; }
int jroc_net_device_status(void) { return ready; }
