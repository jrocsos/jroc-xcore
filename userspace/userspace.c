static int userspace_ready = 0;
void userspace_init(void) { userspace_ready = 1; }
int userspace_status(void) { return userspace_ready; }
