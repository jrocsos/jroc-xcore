#include <stdint.h>

#define KBD_STATUS 0x64
#define KBD_DATA   0x60

static uint8_t inb(uint16_t port)
{
    uint8_t value;

    __asm__ volatile(
        "inb %1, %0"
        : "=a"(value)
        : "Nd"(port)
    );

    return value;
}

int xcore_keyboard_available(void)
{
    return (inb(KBD_STATUS) & 1) != 0;
}

uint8_t xcore_keyboard_read(void)
{
    return inb(KBD_DATA);
}
