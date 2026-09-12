static int drivers_ready = 0;
void drivers_init(void) { drivers_ready = 1; }
int drivers_status(void) { return drivers_ready; }
