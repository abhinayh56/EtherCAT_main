#ifndef ETHERCAT_SLAVE_BASE_H
#define ETHERCAT_SLAVE_BASE_H

#include <ecrt.h>

class EtherCAT_slave_base
{
public:
    virtual void config_slave(ec_master_t *master) {}

    virtual void config_pdo() {};

    virtual void register_pdo_group(ec_domain_t *domain) {}

    virtual void read_pdo() {};

    virtual void set_domain(uint8_t *domain_1_pd) {};
};

#endif // ETHERCAT_SLAVE_BASE_H
