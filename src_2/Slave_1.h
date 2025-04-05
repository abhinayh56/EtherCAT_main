#include <iostream>
#include "EtherCAT_slave_base.h"

class Slave_1 : public EtherCAT_slave_base
{
public:
    // void set_slave_name(const std::string &slave_name_) {}

    // std::string &get_slave_name() const {}

    // void set_slave_address(const uint16_t slave_address_) {}

    // uint16_t get_slave_address() const {}

    // void get_slave_info() {}

    virtual void config_slave(ec_master_t *master) {}

    // bool is_connected() {}

    virtual void register_tx_pdo() {}

    virtual void register_rx_pdo() {}

    // void monitor_status() {}

    virtual void transfer_tx_pdo() {}

    virtual void transfer_rx_pdo() {}

    virtual void process_tx_pdo() {}

    virtual void process_rx_pdo() {}

    virtual void config_data_transfer() {}

    virtual void publish_data() {}

    virtual void subscribe_data() {}

protected:
    // bool connection_status = false;
    // ec_slave_config_t *sc;
    // ec_slave_config_state_t sc_state;
    // uint8_t *domain_1_pd = NULL;
};

#endif // ETHERCAT_SLAVE_BASE_H
