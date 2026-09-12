static int hardware_ready = 0;
void hardware_init(void) { hardware_ready = 1; }
int hardware_status(void) { return hardware_ready; }
