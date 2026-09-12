static int processes_ready = 0;
void process_init(void) { processes_ready = 1; }
int process_status(void) { return processes_ready; }
