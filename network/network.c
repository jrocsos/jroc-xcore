static int network_ready = 0;
void network_init(void) { network_ready = 0; }
int network_status(void) { return network_ready; }
