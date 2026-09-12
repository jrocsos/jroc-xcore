#!/usr/bin/env bash
set -e

cd /workspaces/jroc-xcore

echo "======================================================"
echo "          J-ROC MEGA 1 - CORE RUNTIME"
echo "======================================================"

CFLAGS="-m32 -ffreestanding -fno-pie -fno-stack-protector \
-fno-builtin -nostdlib -nostartfiles -nodefaultlibs"

mkdir -p build/mega1

echo
echo "[1/12] Memory allocator"

cat > xcore/memory/runtime_allocator.c <<'SRC'
#include <stdint.h>

#define JROC_HEAP_START 0x01000000u
#define JROC_HEAP_END   0x02000000u

static uint32_t heap_pointer = JROC_HEAP_START;

void jroc_heap_init(void)
{
    heap_pointer = JROC_HEAP_START;
}

uint32_t jroc_heap_alloc(uint32_t size)
{
    uint32_t aligned;

    if (size == 0)
        return 0;

    aligned = (size + 15u) & ~15u;

    if (heap_pointer > JROC_HEAP_END - aligned)
        return 0;

    uint32_t result = heap_pointer;
    heap_pointer += aligned;

    return result;
}

uint32_t jroc_heap_used(void)
{
    return heap_pointer - JROC_HEAP_START;
}
SRC

echo
echo "[2/12] Paging tables"

cat > xcore/memory/runtime_paging.c <<'SRC'
#include <stdint.h>

#define PAGE_PRESENT 0x001u
#define PAGE_WRITE   0x002u

static uint32_t page_directory[1024]
    __attribute__((aligned(4096)));

static uint32_t first_page_table[1024]
    __attribute__((aligned(4096)));

static int paging_ready = 0;

void jroc_runtime_paging_prepare(void)
{
    uint32_t i;

    for (i = 0; i < 1024; i++)
    {
        first_page_table[i] =
            (i * 0x1000u) |
            PAGE_PRESENT |
            PAGE_WRITE;

        page_directory[i] = 0;
    }

    page_directory[0] =
        ((uint32_t)first_page_table) |
        PAGE_PRESENT |
        PAGE_WRITE;

    paging_ready = 1;
}

int jroc_runtime_paging_status(void)
{
    return paging_ready;
}

uint32_t jroc_runtime_page_directory(void)
{
    return (uint32_t)page_directory;
}
SRC

echo
echo "[3/12] GDT"

cat > xcore/interrupts/runtime_gdt.c <<'SRC'
#include <stdint.h>

struct jroc_gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

static struct jroc_gdt_entry gdt[3];

static void jroc_gdt_set(
    int index,
    uint32_t base,
    uint32_t limit,
    uint8_t access,
    uint8_t granularity)
{
    gdt[index].base_low = base & 0xFFFFu;
    gdt[index].base_middle = (base >> 16) & 0xFFu;
    gdt[index].base_high = (base >> 24) & 0xFFu;

    gdt[index].limit_low = limit & 0xFFFFu;
    gdt[index].granularity = (limit >> 16) & 0x0Fu;
    gdt[index].granularity |= granularity & 0xF0u;

    gdt[index].access = access;
}

void jroc_runtime_gdt_prepare(void)
{
    jroc_gdt_set(0, 0, 0, 0, 0);
    jroc_gdt_set(1, 0, 0xFFFFFFFFu, 0x9A, 0xCF);
    jroc_gdt_set(2, 0, 0xFFFFFFFFu, 0x92, 0xCF);
}
SRC

echo
echo "[4/12] IDT"

cat > xcore/interrupts/runtime_idt.c <<'SRC'
#include <stdint.h>

struct jroc_idt_entry
{
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));

static struct jroc_idt_entry idt[256];

void jroc_runtime_idt_prepare(void)
{
    uint32_t i;

    for (i = 0; i < 256; i++)
    {
        idt[i].base_low = 0;
        idt[i].selector = 0x08;
        idt[i].zero = 0;
        idt[i].flags = 0x8E;
        idt[i].base_high = 0;
    }
}
SRC

echo
echo "[5/12] IRQ state"

cat > xcore/interrupts/runtime_irq.c <<'SRC'
#include <stdint.h>

static volatile uint32_t irq_count = 0;
static volatile uint32_t timer_irq_count = 0;

void jroc_irq_runtime_init(void)
{
    irq_count = 0;
    timer_irq_count = 0;
}

void jroc_irq_runtime_seen(uint8_t irq)
{
    irq_count++;

    if (irq == 0)
        timer_irq_count++;
}

uint32_t jroc_irq_count(void)
{
    return irq_count;
}

uint32_t jroc_timer_irq_count(void)
{
    return timer_irq_count;
}
SRC

echo
echo "[6/12] PIT"

cat > xcore/timer/runtime_pit.c <<'SRC'
#include <stdint.h>

static uint32_t frequency = 100;

void jroc_runtime_pit_set_frequency(
    uint32_t hz)
{
    if (hz)
        frequency = hz;
}

uint32_t jroc_runtime_pit_frequency(void)
{
    return frequency;
}
SRC

echo
echo "[7/12] Process manager"

cat > xcore/process/runtime_process.c <<'SRC'
#include <stdint.h>

#define JROC_MAX_PROCESSES 64

enum
{
    JROC_PROCESS_FREE = 0,
    JROC_PROCESS_READY = 1,
    JROC_PROCESS_RUNNING = 2,
    JROC_PROCESS_BLOCKED = 3,
    JROC_PROCESS_ZOMBIE = 4
};

typedef struct
{
    uint32_t pid;
    uint32_t parent_pid;
    uint32_t entry;
    uint32_t stack;
    uint32_t address_space;
    uint8_t privilege;
    uint8_t state;
} jroc_runtime_process_t;

static jroc_runtime_process_t table[JROC_MAX_PROCESSES];
static uint32_t next_pid = 1;

void jroc_runtime_process_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        table[i].state = JROC_PROCESS_FREE;

    next_pid = 1;
}

int jroc_runtime_process_create(
    uint32_t parent_pid,
    uint32_t entry,
    uint32_t stack,
    uint32_t address_space,
    uint8_t privilege)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
    {
        if (table[i].state == JROC_PROCESS_FREE)
        {
            table[i].pid = next_pid++;
            table[i].parent_pid = parent_pid;
            table[i].entry = entry;
            table[i].stack = stack;
            table[i].address_space = address_space;
            table[i].privilege = privilege;
            table[i].state = JROC_PROCESS_READY;

            return (int)table[i].pid;
        }
    }

    return -1;
}

int jroc_runtime_process_count(void)
{
    int count = 0;
    uint32_t i;

    for (i = 0; i < JROC_MAX_PROCESSES; i++)
        if (table[i].state != JROC_PROCESS_FREE)
            count++;

    return count;
}
SRC

echo
echo "[8/12] Scheduler"

cat > xcore/process/runtime_scheduler.c <<'SRC'
#include <stdint.h>

#define JROC_RUN_QUEUE 64

static uint32_t queue[JROC_RUN_QUEUE];
static uint32_t length = 0;
static uint32_t current = 0;

void jroc_runtime_scheduler_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_RUN_QUEUE; i++)
        queue[i] = 0;

    length = 0;
    current = 0;
}

int jroc_runtime_scheduler_add(uint32_t pid)
{
    if (length >= JROC_RUN_QUEUE)
        return -1;

    queue[length++] = pid;
    return 0;
}

uint32_t jroc_runtime_scheduler_current(void)
{
    if (!length)
        return 0;

    return queue[current];
}

uint32_t jroc_runtime_scheduler_next(void)
{
    if (!length)
        return 0;

    current++;

    if (current >= length)
        current = 0;

    return queue[current];
}
SRC

echo
echo "[9/12] CPU context"

cat > xcore/context/runtime_context.h <<'SRC'
#ifndef JROC_RUNTIME_CONTEXT_H
#define JROC_RUNTIME_CONTEXT_H

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
    uint32_t cr3;

} jroc_runtime_context_t;

#endif
SRC

cat > xcore/context/runtime_context.c <<'SRC'
#include <stdint.h>
#include "runtime_context.h"

void jroc_runtime_context_clear(
    jroc_runtime_context_t *ctx)
{
    uint32_t *p;
    uint32_t i;

    if (!ctx)
        return;

    p = (uint32_t *)ctx;

    for (i = 0;
         i < sizeof(jroc_runtime_context_t) / sizeof(uint32_t);
         i++)
    {
        p[i] = 0;
    }

    ctx->eflags = 0x202;
}
SRC

echo
echo "[10/12] TSS + privilege"

cat > xcore/cpu/runtime_tss.c <<'SRC'
#include <stdint.h>

typedef struct
{
    uint32_t prev;
    uint32_t esp0;
    uint32_t ss0;
    uint32_t esp1;
    uint32_t ss1;
    uint32_t esp2;
    uint32_t ss2;
    uint32_t cr3;
    uint32_t eip;
    uint32_t eflags;
    uint32_t eax;
    uint32_t ecx;
    uint32_t edx;
    uint32_t ebx;
    uint32_t esp;
    uint32_t ebp;
    uint32_t esi;
    uint32_t edi;
    uint32_t es;
    uint32_t cs;
    uint32_t ss;
    uint32_t ds;
    uint32_t fs;
    uint32_t gs;
    uint32_t ldt;
    uint16_t trap;
    uint16_t iomap;
} __attribute__((packed)) jroc_tss_runtime_t;

static jroc_tss_runtime_t tss;
static int ready = 0;

void jroc_runtime_tss_init(
    uint32_t kernel_stack,
    uint16_t kernel_ss)
{
    uint8_t *p = (uint8_t *)&tss;
    uint32_t i;

    for (i = 0; i < sizeof(tss); i++)
        p[i] = 0;

    tss.esp0 = kernel_stack;
    tss.ss0 = kernel_ss;
    tss.iomap = sizeof(tss);

    ready = 1;
}

int jroc_runtime_tss_status(void)
{
    return ready;
}
SRC

cat > xcore/user/runtime_privilege.c <<'SRC'
#include <stdint.h>

int jroc_runtime_selector_is_user(
    uint16_t selector)
{
    return (selector & 3u) == 3u;
}

int jroc_runtime_selector_is_kernel(
    uint16_t selector)
{
    return (selector & 3u) == 0u;
}
SRC

echo
echo "[11/12] Syscalls + IPC"

cat > xcore/syscalls/runtime_syscall.c <<'SRC'
#include <stdint.h>

#define JROC_MAX_SYSCALLS 64

static uint32_t handlers[JROC_MAX_SYSCALLS];

void jroc_runtime_syscall_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_SYSCALLS; i++)
        handlers[i] = 0;
}

int jroc_runtime_syscall_register(
    uint32_t number,
    uint32_t handler)
{
    if (number >= JROC_MAX_SYSCALLS)
        return -1;

    handlers[number] = handler;

    return 0;
}

uint32_t jroc_runtime_syscall_get(
    uint32_t number)
{
    if (number >= JROC_MAX_SYSCALLS)
        return 0;

    return handlers[number];
}

int jroc_runtime_user_pointer_valid(
    uint32_t address,
    uint32_t length)
{
    const uint32_t low = 0x00400000u;
    const uint32_t high = 0xC0000000u;

    if (address < low)
        return 0;

    if (address >= high)
        return 0;

    if (length > high - address)
        return 0;

    return address + length <= high;
}
SRC

cat > xcore/ipc/runtime_ipc.c <<'SRC'
#include <stdint.h>

#define JROC_MAX_CHANNELS 32

typedef struct
{
    uint32_t id;
    uint32_t owner;
    uint32_t receiver;
    uint8_t active;
} jroc_channel_t;

static jroc_channel_t channels[JROC_MAX_CHANNELS];
static uint32_t next_id = 1;

void jroc_runtime_ipc_init(void)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_CHANNELS; i++)
        channels[i].active = 0;

    next_id = 1;
}

int jroc_runtime_ipc_create(
    uint32_t owner,
    uint32_t receiver)
{
    uint32_t i;

    for (i = 0; i < JROC_MAX_CHANNELS; i++)
    {
        if (!channels[i].active)
        {
            channels[i].id = next_id++;
            channels[i].owner = owner;
            channels[i].receiver = receiver;
            channels[i].active = 1;

            return (int)channels[i].id;
        }
    }

    return -1;
}
SRC

echo
echo "[12/12] Compile-checking Mega 1..."

rm -rf build/mega1
mkdir -p build/mega1

COUNT=0

while IFS= read -r src
do
    obj="build/mega1/$(echo "$src" | tr '/' '_').o"

    gcc $CFLAGS -c "$src" -o "$obj"

    echo "OK  $src"

    COUNT=$((COUNT + 1))
done < <(
    find xcore \
        -type f \
        \( -name 'runtime_*.c' \) \
        | sort
)

echo
echo "=============================================="
echo "      J-ROC MEGA 1 CORE COMPILE PASSED"
echo "=============================================="
echo
echo "Runtime modules compiled: $COUNT"
echo
echo "Memory       OK"
echo "Paging       OK"
echo "GDT          OK"
echo "IDT          OK"
echo "IRQ          OK"
echo "PIT          OK"
echo "Processes    OK"
echo "Scheduler    OK"
echo "CPU context  OK"
echo "TSS          OK"
echo "Syscalls     OK"
echo "IPC          OK"
echo
echo "CURRENT BOOT KERNEL WAS NOT REPLACED."
echo
echo "Next:"
echo "  jroc clean"
echo "  jroc build"
