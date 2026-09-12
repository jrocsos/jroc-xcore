static int interrupts_ready = 0;
void interrupts_init(void) { interrupts_ready = 1; }
int interrupts_status(void) { return interrupts_ready; }
