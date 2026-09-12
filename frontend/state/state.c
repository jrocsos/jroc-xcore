static int state_ready = 0;

void jroc_frontend_state_init(void)
{
    state_ready = 1;
}

int jroc_frontend_state_status(void)
{
    return state_ready;
}
