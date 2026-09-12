#ifndef JROC_SYS_H
#define JROC_SYS_H

#include <stdint.h>

#define JROC_SYS_WRITE  1
#define JROC_SYS_READ   2
#define JROC_SYS_OPEN   3
#define JROC_SYS_CLOSE  4
#define JROC_SYS_ALLOC  5
#define JROC_SYS_FREE   6
#define JROC_SYS_SPAWN  7
#define JROC_SYS_EXIT   8
#define JROC_SYS_SLEEP  9
#define JROC_SYS_TIME   10

uint32_t jroc_syscall(
    uint32_t number,
    uint32_t a,
    uint32_t b,
    uint32_t c,
    uint32_t d);

#endif
