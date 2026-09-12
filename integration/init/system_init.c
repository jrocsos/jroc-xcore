/*
 * J-Roc XCore global initialization coordinator.
 *
 * This intentionally uses weak symbols so the coordinator can
 * coexist with builds where some subsystem is not yet linked.
 */

#define JROC_WEAK __attribute__((weak))

/* Core */
extern void memory_manager_init(void) JROC_WEAK;
extern void allocator_init(void) JROC_WEAK;
extern void paging_init(void) JROC_WEAK;
extern void gdt_init(void) JROC_WEAK;
extern void idt_init(void) JROC_WEAK;
extern void irq_init(void) JROC_WEAK;
extern void pit_init(void) JROC_WEAK;

/* Process */
extern void process_init(void) JROC_WEAK;
extern void scheduler_init(void) JROC_WEAK;
extern void cpu_context_init(void) JROC_WEAK;

/* Security */
extern void jroc_identity_init(void) JROC_WEAK;
extern void jroc_auth_init(void) JROC_WEAK;
extern void jroc_security_policy_init(void) JROC_WEAK;
extern void jroc_sandbox_init(void) JROC_WEAK;
extern void jroc_audit_init(void) JROC_WEAK;
extern void jroc_crypto_init(void) JROC_WEAK;

/* Services */
extern void jroc_service_manager_init(void) JROC_WEAK;
extern void jroc_logging_init(void) JROC_WEAK;
extern void jroc_update_init(void) JROC_WEAK;
extern void jroc_service_ipc_init(void) JROC_WEAK;

/* Userspace */
extern void jroc_userspace_init(void) JROC_WEAK;
extern void jroc_runtime_init(void) JROC_WEAK;
extern void jroc_shell_init(void) JROC_WEAK;

/* Networking */
extern void jroc_network_init(void) JROC_WEAK;

/* Desktop */
extern void jroc_desktop_init(void) JROC_WEAK;
extern void jroc_window_manager_init(void) JROC_WEAK;
extern void jroc_settings_init(void) JROC_WEAK;
extern void jroc_file_manager_init(void) JROC_WEAK;
extern void jroc_notifications_init(void) JROC_WEAK;
extern void jroc_theme_init(void) JROC_WEAK;
extern void jroc_desktop_input_init(void) JROC_WEAK;

/* Frontend */
extern void jroc_frontend_init(void) JROC_WEAK;
extern void jroc_widgets_init(void) JROC_WEAK;
extern void jroc_navigation_init(void) JROC_WEAK;
extern void jroc_frontend_state_init(void) JROC_WEAK;

static int initialized = 0;

static void call_if_present(void (*fn)(void))
{
    if (fn)
        fn();
}

void jroc_system_init(void)
{
    if (initialized)
        return;

    /*
     * Core
     */
    call_if_present(memory_manager_init);
    call_if_present(allocator_init);
    call_if_present(paging_init);
    call_if_present(gdt_init);
    call_if_present(idt_init);
    call_if_present(irq_init);
    call_if_present(pit_init);

    /*
     * Process
     */
    call_if_present(process_init);
    call_if_present(scheduler_init);
    call_if_present(cpu_context_init);

    /*
     * Security
     */
    call_if_present(jroc_identity_init);
    call_if_present(jroc_auth_init);
    call_if_present(jroc_security_policy_init);
    call_if_present(jroc_sandbox_init);
    call_if_present(jroc_audit_init);
    call_if_present(jroc_crypto_init);

    /*
     * Services
     */
    call_if_present(jroc_service_manager_init);
    call_if_present(jroc_logging_init);
    call_if_present(jroc_update_init);
    call_if_present(jroc_service_ipc_init);

    /*
     * Networking
     */
    call_if_present(jroc_network_init);

    /*
     * Userspace
     */
    call_if_present(jroc_userspace_init);
    call_if_present(jroc_runtime_init);
    call_if_present(jroc_shell_init);

    /*
     * Desktop + frontend
     */
    call_if_present(jroc_desktop_init);
    call_if_present(jroc_window_manager_init);
    call_if_present(jroc_settings_init);
    call_if_present(jroc_file_manager_init);
    call_if_present(jroc_notifications_init);
    call_if_present(jroc_theme_init);
    call_if_present(jroc_desktop_input_init);

    call_if_present(jroc_frontend_init);
    call_if_present(jroc_widgets_init);
    call_if_present(jroc_navigation_init);
    call_if_present(jroc_frontend_state_init);

    initialized = 1;
}

int jroc_system_initialized(void)
{
    return initialized;
}
