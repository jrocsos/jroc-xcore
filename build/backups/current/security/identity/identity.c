static int ready;

void jroc_identity_init(void) { ready = 1; }
int jroc_identity_status(void) { return ready; }
