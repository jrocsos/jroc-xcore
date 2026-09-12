#include <assert.h>

void jroc_address_space_init(void);
int jroc_address_space_create(unsigned int);
int jroc_address_space_valid(unsigned int);
int jroc_address_valid(
    unsigned int,
    unsigned int,
    unsigned int);

int main(void)
{
    jroc_address_space_init();

    int id = jroc_address_space_create(0x00100000);

    assert(id > 0);
    assert(jroc_address_space_valid(id));

    assert(jroc_address_valid(
        id,
        0x00400000,
        4096));

    return 0;
}
