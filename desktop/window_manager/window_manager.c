static int ready;

void jroc_window_manager_init(void) { ready = 1; }
int jroc_window_manager_status(void) { return ready; }
