#ifndef ETHERCAT_SLAVE_1_H
#define ETHERCAT_SLAVE_1_H

#include <iostream>
#include "../src/EtherCAT_slave_base/EtherCAT_slave_base.h"

class EtherCAT_slave_1 : public EtherCAT_slave_base
{
public:
    EtherCAT_slave_1() {};

    ~EtherCAT_slave_1() {}
    
    void register_tx_pdo(Pdo_info *tx_pdo_list_) {}

    void register_rx_pdo(Pdo_info *rx_pdo_list_) {}

    void config_data_transfer() {}

    void process_tx_pdo() {}

    void process_rx_pdo() {}

    void publish_data() {}

    void subscribe_data() {}
};

#endif // ETHERCAT_SLAVE_1_H
