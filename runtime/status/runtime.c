#include <stdint.h>

typedef struct
{
    uint8_t booted;
    uint8_t core;
    uint8_t security;
    uint8_t services;
    uint8_t storage;
    uint8_t network;
    uint8_t userspace;
    uint8_t desktop;
} jroc_runtime_state_t;

static jroc_runtime_state_t state;

void jroc_runtime_reset(void)
{
    state.booted = 0;
    state.core = 0;
    state.security = 0;
    state.services = 0;
    state.storage = 0;
    state.network = 0;
    state.userspace = 0;
    state.desktop = 0;
}

void jroc_runtime_boot(void)
{
    state.booted = 1;
}

void jroc_runtime_set_core(int value)
{
    state.core = value ? 1 : 0;
}

void jroc_runtime_set_security(int value)
{
    state.security = value ? 1 : 0;
}

void jroc_runtime_set_services(int value)
{
    state.services = value ? 1 : 0;
}

void jroc_runtime_set_storage(int value)
{
    state.storage = value ? 1 : 0;
}

void jroc_runtime_set_network(int value)
{
    state.network = value ? 1 : 0;
}

void jroc_runtime_set_userspace(int value)
{
    state.userspace = value ? 1 : 0;
}

void jroc_runtime_set_desktop(int value)
{
    state.desktop = value ? 1 : 0;
}

int jroc_runtime_ready(void)
{
    return state.booted &&
           state.core;
}

int jroc_runtime_full_stack_ready(void)
{
    return state.booted &&
           state.core &&
           state.security &&
           state.services &&
           state.storage &&
           state.network &&
           state.userspace &&
           state.desktop;
}
