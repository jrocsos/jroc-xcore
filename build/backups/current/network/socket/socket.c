static int ready;

void jroc_socket_init(void) { ready = 1; }
int jroc_socket_status(void) { return ready; }
