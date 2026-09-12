static int ready;

void jroc_disk_init(void) { ready = 1; }
int jroc_disk_status(void) { return ready; }
