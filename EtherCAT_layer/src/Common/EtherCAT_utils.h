#ifndef ETHERCAT_UTILS_H
#define ETHERCAT_UTILS_H

#include <ecrt.h>
#include <stdint.h>

template <typename T_value>
struct Pdo_info
{
    uint16_t index = 0;
    uint8_t subindex = 0;
    uint32_t *offset = nullptr;
    uint32_t *bit_position = nullptr;
    T_value t_value = 0;
    bool is_supported = false;
};

#endif // ETHERCAT_UTILS_H
