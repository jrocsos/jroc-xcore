static int services_ready = 0;
void services_init(void) { services_ready = 1; }
int services_status(void) { return services_ready; }
