static int health_ready;

void jroc_health_init(void)
{
    health_ready = 1;
}

int jroc_health_status(void)
{
    return health_ready;
}
