#include <unistd.h>
#include <iostream>
#include "EtherCAT_master/EtherCAT_master.h"
#include "Slaves/EtherCAT_slave_1.h"
#include "Slaves/EtherCAT_slave_2.h"

EtherCAT_master ec_master;

EtherCAT_slave_1 slave_1;
EtherCAT_slave_2 slave_2;

int main()
{
    ec_master.add_slave(&slave_1);
    ec_master.add_slave(&slave_2);

    ec_master.config();

    while (ec_master.run)
    {
        ec_master.cyclic_task();
        usleep(4000);
    }

    return 0;
}