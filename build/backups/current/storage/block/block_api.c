static int ready = 0;

void jroc_block_api_init(void)
{
    ready = 1;
}

int jroc_block_api_status(void)
{
    return ready;
}
