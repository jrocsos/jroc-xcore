#include <stdint.h>

void jroc_pcb_init(void);
int jroc_process_create(uint32_t, uint8_t);
int jroc_process_count(void);

int main(void)
{
    jroc_pcb_init();

    if (jroc_process_count() != 0)
        return 1;

    if (jroc_process_create(0, 0) <= 0)
        return 2;

    if (jroc_process_count() != 1)
        return 3;

    return 0;
}
