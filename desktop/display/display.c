static int ready;

void jroc_display_init(void) { ready = 1; }
int jroc_display_status(void) { return ready; }
