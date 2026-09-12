#include <assert.h>

void jroc_context_handoff_init(void);
void jroc_context_handoff_set(
    unsigned int,
    unsigned int);
int jroc_context_switch_required(void);

int main(void)
{
    jroc_context_handoff_init();

    jroc_context_handoff_set(1, 2);
    assert(jroc_context_switch_required());

    jroc_context_handoff_set(2, 2);
    assert(!jroc_context_switch_required());

    return 0;
}
