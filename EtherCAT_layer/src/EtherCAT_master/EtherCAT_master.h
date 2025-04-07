#ifndef ETHERCAT_MASTER_H
#define ETHERCAT_MASTER_H

#include <ecrt.h>
#include <vector>
#include <iostream>
#include "Data_transfer.h"
#include "../Logger/Logger_console/Logger_console.h"
#include "../EtherCAT_slave_base/EtherCAT_slave_base.h"

#define CYCLIC_SLAVE_CALL_PARALLEL
// #define CYCLIC_SLAVE_CALL_SEQUENTIAL

class EtherCAT_master : public Data_transfer
{
public:
    EtherCAT_master(); // done
    ~EtherCAT_master(); // done
    void add_slave(EtherCAT_slave_base *new_slave); // done
    void config(); // done
    void cyclic_task(); // done

protected:
    ec_master_t *master = NULL;
    ec_master_state_t master_state = {};
    ec_domain_t *domain_1 = NULL;
    ec_domain_state_t domain_1_state = {};
    uint8_t *domain_1_pd = NULL;
    bool run = false;

private:
    unsigned int num_slaves = 0;
    std::vector<EtherCAT_slave_base *> slave_base_arr;

    bool start(); // done
    bool stop(); // stop
    bool create_domain(); // done
    void configure_slaves(); // done
    void register_pdo(); // done
    void config_data_transfer() // done
    void create_pdo_config(); // done
    void register_pdo_group(); // done
    bool activate(); // done
    bool get_domain_process_data(); // done
    void set_domain_process_data(); // done
    void monitor_status(); // done
    void transfer_tx_pdo(); // done
    void process_tx_pdo(); // done
    void publish_data(); // done
    void subscribe_data(); // done
    void process_rx_pdo(); // done
    void transfer_rx_pdo(); // done
};

#endif // ETHERCAT_MASTER_H
