static int irq_ready = 0;

void xcore_irq_init(void)
{
    irq_ready = 1;
}

int xcore_irq_status(void)
{
    return irq_ready;
}
