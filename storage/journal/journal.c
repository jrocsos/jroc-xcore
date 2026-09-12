#include <stdint.h>

#define JROC_JOURNAL_MAX 128

static uint32_t transaction_count = 0;
static uint8_t active = 0;

void jroc_journal_init(void)
{
    transaction_count = 0;
    active = 0;
}

void jroc_journal_begin(void)
{
    active = 1;
}

void jroc_journal_commit(void)
{
    if (active)
    {
        transaction_count++;
        active = 0;
    }
}

uint32_t jroc_journal_transactions(void)
{
    return transaction_count;
}
