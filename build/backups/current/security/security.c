static int security_ready = 0;
void security_init(void) { security_ready = 1; }
int security_status(void) { return security_ready; }
