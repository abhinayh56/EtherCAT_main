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
    EtherCAT_master();
    ~EtherCAT_master();
    void add_slave(EtherCAT_slave_base *new_slave);
    bool start();
    void config();
    void cyclic_task();
    bool is_running();

private:
    unsigned int num_slaves = 0;
    std::vector<EtherCAT_slave_base *> slave_base_arr;

    ec_master_t *master = NULL;
    ec_master_state_t master_state = {};
    ec_domain_t *domain_1 = NULL;
    ec_domain_state_t domain_1_state = {};
    uint8_t *domain_1_pd = NULL;
    bool run = false;

    bool stop();
    bool create_domain();
    void configure_slaves();
    void config_data_transfer();
    void register_pdo_to_domain();
    bool activate();
    bool get_domain_process_data();
    void set_domain_process_data();
    void monitor_status();

    void transfer_tx_pdo();
    void process_tx_pdo();
    void publish_data();
    void subscribe_data();
    void process_rx_pdo();
    void transfer_rx_pdo();
};

#endif // ETHERCAT_MASTER_H
