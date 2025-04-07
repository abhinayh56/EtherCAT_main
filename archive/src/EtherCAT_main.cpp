#include "EtherCAT_master.h"
#include "EtherCAT_slave_1.h"
#include "EtherCAT_slave_2.h"
#include "EtherCAT_slave_3.h"
#include "EtherCAT_slave_4.h"
#include "EtherCAT_slave_5.h"
#include <unistd.h>
#include <iostream>

EtherCAT_master ec_master;

EtherCAT_slave_1 slave_1;
EtherCAT_slave_2 slave_2;
EtherCAT_slave_3 slave_3;
EtherCAT_slave_4 slave_4;
EtherCAT_slave_5 slave_5;

int main()
{
    ec_master.add_slave(&slave_1);
    ec_master.add_slave(&slave_2);
    ec_master.add_slave(&slave_3);
    ec_master.add_slave(&slave_4);
    ec_master.add_slave(&slave_5);

    ec_master.config();

    while (ec_master.run)
    {
        ec_master.cyclic_task();
        usleep(4000);
    }

    return 0;
}
