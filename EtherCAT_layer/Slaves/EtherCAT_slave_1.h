#ifndef ETHERCAT_SLAVE_1_H
#define ETHERCAT_SLAVE_1_H

#include <iostream>
#include "../src/EtherCAT_slave_base/EtherCAT_slave_base.h"

class EtherCAT_slave_1 : public EtherCAT_slave_base
{
public:
    EtherCAT_slave_1() {};
    
    ~EtherCAT_slave_1() {}

    virtual void register_tx_pdo() {}

    virtual void register_rx_pdo() {}

    virtual void config_data_transfer() {}

    virtual void process_tx_pdo() {}

    virtual void process_rx_pdo() {}

    virtual void publish_data() {}

    virtual void subscribe_data() {}
};

#endif // ETHERCAT_SLAVE_1_H
