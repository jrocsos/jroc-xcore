#include <stdint.h>

typedef struct
{
    uint32_t type;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
} jroc_ui_element_t;

int jroc_ui_element_valid(
    const jroc_ui_element_t *element)
{
    if (!element)
        return 0;

    if (element->width == 0 ||
        element->height == 0)
        return 0;

    return 1;
}
