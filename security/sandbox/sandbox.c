static int ready;

void jroc_sandbox_init(void) { ready = 1; }
int jroc_sandbox_status(void) { return ready; }
