static int ready;

void jroc_runtime_init(void) { ready = 1; }
int jroc_runtime_status(void) { return ready; }
