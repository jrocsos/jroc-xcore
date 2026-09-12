static int kernel_ready;
static int memory_ready;
static int process_ready;
static int storage_ready;
static int network_ready;
static int security_ready;
static int services_ready;
static int userspace_ready;
static int desktop_ready;
static int sdk_ready;

void jroc_platform_registry_init(void)
{
    kernel_ready = 1;
    memory_ready = 1;
    process_ready = 1;
    storage_ready = 1;
    network_ready = 1;
    security_ready = 1;
    services_ready = 1;
    userspace_ready = 1;
    desktop_ready = 1;
    sdk_ready = 1;
}

int jroc_platform_ready(void)
{
    return kernel_ready &&
           memory_ready &&
           process_ready &&
           storage_ready &&
           network_ready &&
           security_ready &&
           services_ready &&
           userspace_ready &&
           desktop_ready &&
           sdk_ready;
}
