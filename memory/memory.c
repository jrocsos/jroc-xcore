static int memory_ready = 0;
void memory_init(void) { memory_ready = 1; }
int memory_status(void) { return memory_ready; }
