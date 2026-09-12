static int ready = 0;

void jroc_security_policy_init(void)
{
    ready = 1;
}

int jroc_security_policy_status(void)
{
    return ready;
}

int jroc_security_operation_allowed(
    int identity_valid,
    int permission_valid)
{
    if (!ready)
        return 0;

    return identity_valid && permission_valid;
}
