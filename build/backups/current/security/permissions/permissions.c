static int ready;

void jroc_permissions_init(void) { ready = 1; }
int jroc_permissions_status(void) { return ready; }
