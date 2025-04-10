#ifndef ETHERCAT_SLAVE_1_H
#define ETHERCAT_SLAVE_1_H

#include <iostream>
#include "../src/EtherCAT_slave_base/EtherCAT_slave_base.h"

class EtherCAT_slave_1 : public EtherCAT_slave_base
{
public:
    EtherCAT_slave_1(const uint16_t slave_address_, const std::string &slave_name_)
    {
        slave_address = slave_address_;
        slave_name = slave_name_;
    }

    ~EtherCAT_slave_1() {}

    void register_tx_pdo() {}

    void register_rx_pdo() {}

    void config_data_transfer() {}

    void process_tx_pdo() {}

    void process_rx_pdo() {}

    void publish_data() {}

    void subscribe_data() {}
};

#endif // ETHERCAT_SLAVE_1_H
