#include <stdint.h>

static int crypto_ready = 0;

void jroc_crypto_init(void)
{
    crypto_ready = 1;
}

int jroc_crypto_status(void)
{
    return crypto_ready;
}

uint32_t jroc_checksum32(
    const uint8_t *data,
    uint32_t length)
{
    uint32_t result = 0;
    uint32_t i;

    if (!data)
        return 0;

    for (i = 0; i < length; i++)
        result = (result << 5) -
                 result +
                 data[i];

    return result;
}
