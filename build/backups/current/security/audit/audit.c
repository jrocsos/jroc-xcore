static int ready;

void jroc_audit_init(void) { ready = 1; }
int jroc_audit_status(void) { return ready; }
