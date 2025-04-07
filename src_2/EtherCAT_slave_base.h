#ifndef ETHERCAT_SLAVE_BASE_H
#define ETHERCAT_SLAVE_BASE_H

#include <ecrt.h>
#include <string>
#include <stdint.h>
#include <iostream>
#include "Data_transfer.h"

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

class EtherCAT_slave_base : public Data_transfer
{
public:
    void set_slave_name(const std::string &slave_name_)
    {
        slave_name = slave_name_;
    }

    std::string &get_slave_name() const
    {
        return slave_name;
    }

    void set_slave_address(const uint16_t slave_address_)
    {
        slave_address = slave_address_;
    }

    uint16_t get_slave_address() const
    {
        return slave_address;
    }

    void set_slave_info() {}

    void get_slave_info() {}

    void config_slave(ec_master_t *master)
    {
        // set_slave_name(const std::string &slave_name_)
        // set_slave_address(const uint16_t slave_address_)
        // uint16_t alias = 0;
        // uint16_t position = 9;
        // uint32_t vendor_id = 0x00113322;
        // uint32_t product_code = 0x00001022;
        // connection_status = false
    }

    bool is_connected()
    {
        return connection_status;
    }

    virtual void register_tx_pdo() {}

    virtual void register_rx_pdo() {}

    void monitor_status() {}

    void transfer_tx_pdo() {}

    void transfer_rx_pdo() {}

    virtual void process_tx_pdo() {}

    virtual void process_rx_pdo() {}

private:
    std::string slave_name;
    uint16_t slave_address;
    Slave_info slave_info;
    bool connection_status = false;
    
    ec_slave_config_t *sc;
    ec_slave_config_state_t sc_state;
    uint8_t *domain_1_pd = NULL;
};

#endif // ETHERCAT_SLAVE_BASE_H
