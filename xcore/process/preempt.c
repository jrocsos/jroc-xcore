static int preemption_ready = 0;

void jroc_preemption_init(void)
{
    preemption_ready = 1;
}

int jroc_preemption_status(void)
{
    return preemption_ready;
}

int jroc_preemption_required(int scheduler_switch)
{
    return scheduler_switch ? 1 : 0;
}
