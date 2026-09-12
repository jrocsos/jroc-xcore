enum {
    JROC_CAP_MEMORY = 1,
    JROC_CAP_PROCESS,
    JROC_CAP_STORAGE,
    JROC_CAP_NETWORK,
    JROC_CAP_SECURITY,
    JROC_CAP_SERVICES,
    JROC_CAP_USERSPACE,
    JROC_CAP_DESKTOP,
    JROC_CAP_PACKAGES,
    JROC_CAP_AI,
    JROC_CAP_CLOUD
};

int jroc_capability_available(int capability)
{
    switch (capability)
    {
        case JROC_CAP_MEMORY:
        case JROC_CAP_PROCESS:
        case JROC_CAP_STORAGE:
        case JROC_CAP_NETWORK:
        case JROC_CAP_SECURITY:
        case JROC_CAP_SERVICES:
        case JROC_CAP_USERSPACE:
        case JROC_CAP_DESKTOP:
        case JROC_CAP_PACKAGES:
            return 1;

        case JROC_CAP_AI:
        case JROC_CAP_CLOUD:
            return 0;

        default:
            return 0;
    }
}
