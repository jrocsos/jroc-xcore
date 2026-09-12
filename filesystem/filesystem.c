static int filesystem_ready = 0;
void filesystem_init(void) { filesystem_ready = 1; }
int filesystem_status(void) { return filesystem_ready; }
