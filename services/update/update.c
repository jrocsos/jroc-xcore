static int ready;

void jroc_update_init(void) { ready = 1; }
int jroc_update_status(void) { return ready; }
