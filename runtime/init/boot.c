#include <stdint.h>

extern void jroc_runtime_reset(void);
extern void jroc_runtime_boot(void);
extern void jroc_runtime_set_core(int);
extern void jroc_runtime_set_security(int);
extern void jroc_runtime_set_services(int);
extern void jroc_runtime_set_storage(int);
extern void jroc_runtime_set_network(int);
extern void jroc_runtime_set_userspace(int);
extern void jroc_runtime_set_desktop(int);

extern void jroc_runtime_console_init(void);

static uint8_t boot_sequence_complete = 0;

void jroc_runtime_boot_init(void)
{
    /*
     * Reset global runtime state first.
     */
    jroc_runtime_reset();

    /*
     * Initialize the runtime console.
     */
    jroc_runtime_console_init();

    /*
     * Mark the kernel/runtime as booted.
     */
    jroc_runtime_boot();

    /*
     * These represent the currently available subsystem
     * boundaries. They can be replaced with real initialization
     * results as each subsystem becomes hardware-complete.
     */
    jroc_runtime_set_core(1);
    jroc_runtime_set_security(1);
    jroc_runtime_set_services(1);
    jroc_runtime_set_storage(1);
    jroc_runtime_set_network(1);
    jroc_runtime_set_userspace(1);
    jroc_runtime_set_desktop(1);

    boot_sequence_complete = 1;
}

int jroc_boot_sequence_complete(void)
{
    return boot_sequence_complete;
}
