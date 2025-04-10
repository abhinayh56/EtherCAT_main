#ifndef ETHERCAT_UTILS_H
#define ETHERCAT_UTILS_H

#include <ecrt.h>
#include <stdint.h>

struct Pdo_variable
{
    uint16_t index = 0;
    uint8_t subindex = 0;
    uint32_t *offset = nullptr;
    bool is_supported = false;
};

struct Slave_info
{
    uint16_t alias;
    uint16_t position;
    uint32_t vendor_id;
    uint32_t product_code;

    ec_pdo_entry_info_t *slave_pdo_entries;
    ec_pdo_info_t *slave_pdos;
    ec_sync_info_t *slave_syncs;
};

#endif // ETHERCAT_UTILS_H
