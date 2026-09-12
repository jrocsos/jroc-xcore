static int ready;

void jroc_filesystem_init(void) { ready = 1; }
int jroc_filesystem_status(void) { return ready; }
