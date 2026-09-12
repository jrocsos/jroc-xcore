static unsigned long events;

void jroc_logging_init(void) { events = 0; }
void jroc_log_event(void) { events++; }
unsigned long jroc_log_count(void) { return events; }
