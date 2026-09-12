#include <assert.h>

void jroc_ipc_init(void);

int jroc_ipc_channel_create(
    unsigned int,
    unsigned int);

int jroc_ipc_channel_valid(
    unsigned int);

int main(void)
{
    jroc_ipc_init();

    int id = jroc_ipc_channel_create(1, 2);

    assert(id > 0);
    assert(jroc_ipc_channel_valid(id));

    return 0;
}
