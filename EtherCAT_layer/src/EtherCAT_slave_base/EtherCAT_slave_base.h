#ifndef ETHERCAT_SLAVE_BASE_H
#define ETHERCAT_SLAVE_BASE_H

#include <ecrt.h>
#include <string>
#include <stdint.h>
#include <iostream>
#include "../Common/Data_transfer.h"
#include "../Logger/Logger_console/Logger_console.h"

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
    EtherCAT_slave_base();
    ~EtherCAT_slave_base();
    void set_slave_name(const std::string &slave_name_);
    std::string &get_slave_name() const;
    void set_slave_address(const uint16_t slave_address_);
    uint16_t get_slave_address() const;
    void set_slave_info();
    void get_slave_info();
    void config_slave(ec_master_t *master);
    bool is_connected();
    void register_pdo_to_domain();
    void register_tx_pdo();
    void register_rx_pdo();
    void set_domain();
    void monitor_status();
    void transfer_tx_pdo();
    void transfer_rx_pdo();
    virtual void process_tx_pdo();
    virtual void process_rx_pdo();

private:
    std::string slave_name;
    uint16_t slave_address;
    Slave_info slave_info;

    bool connection_status = false;
    ec_slave_config_t *sc;
    ec_slave_config_state_t sc_state;
    uint8_t *domain_i_pd = NULL;
};

#endif // ETHERCAT_SLAVE_BASE_H
