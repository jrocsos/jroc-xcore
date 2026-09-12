static int ready;

void jroc_block_init(void) { ready = 1; }
int jroc_block_status(void) { return ready; }
