static int ready;

void jroc_crypto_init(void) { ready = 1; }
int jroc_crypto_status(void) { return ready; }
