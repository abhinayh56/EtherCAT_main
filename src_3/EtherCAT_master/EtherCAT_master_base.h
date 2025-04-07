#ifndef ETHERCAT_MASTER_BASE_H
#define ETHERCAT_MASTER_BASE_H

#include <ecrt.h>
#include <vector>
#include <iostream>
#include "Data_transfer.h"
#include "EtherCAT_slave_base.h"

class EtherCAT_master_base : public Data_transfer
{
public:
    EtherCAT_master_base();
    ~EtherCAT_master_base();
    void add_slave(EtherCAT_slave_base *new_slave);
    void config();
    void cyclic_task();

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

    bool start();
    bool stop();
    bool create_domain();
    void configure_slaves();
    void create_pdo_config();
    void register_pdo_group();
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

#endif // ETHERCAT_MASTER_BASE_H
