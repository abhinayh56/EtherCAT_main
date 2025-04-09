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

    Rx_pdo *rx_pdo;
    Tx_pdo *tx_pdo;

    ec_pdo_entry_info_t *slave_pdo_entries;
    ec_pdo_info_t *slave_pdos;
    ec_sync_info_t *slave_syncs;
};

template <uint16_t index_, uint8_t subindex_, typenamet T_value>
struct Pdo_variable
{
    uint16_t index = index_ = 0;
    uint8_t subindex = sub_index_ = 0;
    uint32_t *offset = NULL;
    uint32_t *bit_position = NULL;
    T_value value = 0;
    bool is_supported = false;
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
    void set_slave_info(); // TODO
    void get_slave_info(); // TODO
    void config_slave(ec_master_t *master);
    bool is_connected();
    void register_pdo_to_domain(ec_domain_t *domain_i); // TODO
    void set_domain(uint8_t *domain_i_pd_);
    void monitor_status();  // TODO
    void transfer_tx_pdo(); // TODO
    void transfer_rx_pdo(); // TODO
    virtual void process_tx_pdo() = 0;
    virtual void process_rx_pdo() = 0;

protected:
    virtual void register_tx_pdo(Pdo_list *tx_pdo_list_) = 0;
    virtual void register_rx_pdo(Pdo_list *rx_pdo_list_) = 0;

private:
    std::string slave_name;
    uint16_t slave_address;
    Slave_info slave_info;

    bool connection_status = false;
    ec_slave_config_t *sc;
    ec_slave_config_state_t sc_state;
    uint8_t *domain_i_pd = NULL;

    Pdo_list *tx_pdo_list = NULL;
    Pdo_list *rx_pdo_list = NULL;

    ec_pdo_entry_reg_t *domain_regs;
};

#endif // ETHERCAT_SLAVE_BASE_H
