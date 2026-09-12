#include <stdint.h>

static void outb(uint16_t port, uint8_t value)
{
    __asm__ volatile(
        "outb %0, %1"
        :
        : "a"(value), "Nd"(port)
    );
}

void xcore_pit_init(void)
{
    uint16_t divisor =
        (uint16_t)(1193180u / 100u);

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xFF);
    outb(0x40, divisor >> 8);
}
