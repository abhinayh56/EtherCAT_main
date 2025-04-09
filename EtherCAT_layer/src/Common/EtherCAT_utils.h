#ifndef ETHERCAT_UTILS_H
#define ETHERCAT_UTILS_H

#include <ecrt.h>
#include <stdint.h>

struct Pdo_variable
{
    uint16_t index = 0;
    uint8_t subindex = 0;
    uint32_t *offset = NULL;
};

#endif // ETHERCAT_UTILS_H
