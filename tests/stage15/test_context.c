#include <assert.h>
#include <stdint.h>

typedef struct
{
    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t eip;
    uint32_t eflags;
    uint32_t cs;
    uint32_t ss;
} context_t;

int main(void)
{
    context_t ctx = {0};

    ctx.cs = 0x08;
    ctx.ss = 0x10;

    assert(ctx.cs != 0);
    assert(ctx.ss != 0);

    assert(sizeof(context_t) ==
           12 * sizeof(uint32_t));

    return 0;
}
