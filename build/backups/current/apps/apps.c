static int apps_ready = 0;
void apps_init(void) { apps_ready = 1; }
int apps_status(void) { return apps_ready; }
