#include <assert.h>

void jroc_socket_manager_init(void);
int jroc_socket_open(unsigned char);
int jroc_socket_valid(unsigned int);

int main(void)
{
    jroc_socket_manager_init();

    int socket_id = jroc_socket_open(6);

    assert(socket_id > 0);
    assert(jroc_socket_valid(socket_id));

    return 0;
}
