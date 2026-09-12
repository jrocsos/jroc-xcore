#include <stdint.h>

typedef struct
{
    uint32_t core;
    uint32_t security;
    uint32_t services;
    uint32_t network;
    uint32_t userspace;
    uint32_t desktop;
    uint32_t frontend;
} jroc_system_status_t;

static jroc_system_status_t status;

void jroc_status_reset(void)
{
    status.core = 0;
    status.security = 0;
    status.services = 0;
    status.network = 0;
    status.userspace = 0;
    status.desktop = 0;
    status.frontend = 0;
}

void jroc_status_set_core(uint32_t value)
{
    status.core = value;
}

void jroc_status_set_security(uint32_t value)
{
    status.security = value;
}

void jroc_status_set_services(uint32_t value)
{
    status.services = value;
}

void jroc_status_set_network(uint32_t value)
{
    status.network = value;
}

void jroc_status_set_userspace(uint32_t value)
{
    status.userspace = value;
}

void jroc_status_set_desktop(uint32_t value)
{
    status.desktop = value;
}

void jroc_status_set_frontend(uint32_t value)
{
    status.frontend = value;
}

uint32_t jroc_status_core(void)
{
    return status.core;
}

uint32_t jroc_status_security(void)
{
    return status.security;
}

uint32_t jroc_status_services(void)
{
    return status.services;
}

uint32_t jroc_status_network(void)
{
    return status.network;
}

uint32_t jroc_status_userspace(void)
{
    return status.userspace;
}

uint32_t jroc_status_desktop(void)
{
    return status.desktop;
}

uint32_t jroc_status_frontend(void)
{
    return status.frontend;
}
