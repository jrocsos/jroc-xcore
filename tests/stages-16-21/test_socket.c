#include <assert.h>

void jroc_socket_api_init(void);
int jroc_socket_create(unsigned char);

int main(void)
{
    jroc_socket_api_init();

    assert(jroc_socket_create(6) > 0);

    return 0;
}
