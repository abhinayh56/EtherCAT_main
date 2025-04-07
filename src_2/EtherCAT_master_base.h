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
    EtherCAT_master_base() {}
    ~EtherCAT_master_base() {}

    void add_slave(EtherCAT_slave_base *new_slave)
    {
        slave_base_arr.push_back(new_slave);
        num_slaves = slave_base_arr.size();
    }

    void config()
    {
        // Perform master configuration
        // Scan for slaves and bus configuration
        // Perform slave configuration

        // 1. Start master
        start();

        // 2. Create domain
        create_domain();

        config_slave();
        register_tx_pdo();
        register_rx_pdo();
        config_data_transfer();

        // 3. Configure slave_i; i = 0, 1, ...
        configure_slaves();

        // 4. Create PDO configuration for slave_i; i = 0, 1, ...
        create_pdo_config();

        // 5. Register group of PDOs to a domain
        register_pdo_group();

        // 6. Finishes configuration and activates master
        activate();

        // 7. Get pointer to domain process data
        get_domain_process_data();

        // 8. Provide pointer to domain process data to slaves
        set_domain_process_data();

        run = true;
    }

    void cyclic_task()
    {
        if (run)
        {
            // 1. Fetches received frames from the hardware and processes the datagrams
            ecrt_master_receive(master);

            // 2. Determines the states of the domain's datagrams
            ecrt_domain_process(domain_1);

            // 3. Reads the state of a domain
            ecrt_domain_state(domain_1, &domain_1_state);

            // 4. Monitor status
            monitor_status();

            // 5. Transfer tx_pdo
            transfer_tx_pdo();

            // 6. Process tx_pdo
            process_tx_pdo();

            // 7. Publish tx_pdo data
            publish_data();

            // 8. Subscribe rx_pdo data
            subscribe_data();

            // 9. Process rx_pdo data
            process_rx_pdo();

            // 10. Transfer rx_pdo
            transfer_rx_pdo();

            // 11. Send process data
            ecrt_domain_queue(domain_1);
            ecrt_master_send(master);

            // 9. Check master state
            ecrt_master_state(master, &master_state);

            // 10. Check of slave_i; i = 0, 1, ...
            // TODO
        }
        else
        {
            stop();
        }
    }

    bool run = false;

protected:
    ec_master_t *master = NULL;
    ec_master_state_t master_state = {};
    ec_domain_t *domain_1 = NULL;
    ec_domain_state_t domain_1_state = {};
    uint8_t *domain_1_pd = NULL;

private:
    unsigned int num_slaves = 0;
    std::vector<EtherCAT_slave_base *> slave_base_arr;

    bool start()
    {
        std::cout << "creating master..." << std::endl;
        master = ecrt_request_master(0);
        if (master)
        {
            std::cout << "master creation done" << std::endl;
            return true;
        }
        else
        {
            std::cout << "master creation failed" << std::endl;
            return false;
        }
    }

    bool stop()
    {
        std::cout << "stopping master..." << std::endl;
        ecrt_release_master(master);
        std::cout << "master stopped" << std::endl;
        return true;
    }

    bool create_domain()
    {
        std::cout << "creating domain..." << std::endl;
        domain_1 = ecrt_master_create_domain(master);
        if (domain_1)
        {
            std::cout << "domain creation done" << std::endl;
            return true;
        }
        else
        {
            std::cout << "domain creation failed" << std::endl;
            return false;
        }
    }

    void configure_slaves()
    {
        std::cout << "configuring slaves..." << std::endl;
        for (int i = 0; i < num_slaves; i++)
        {
            std::cout << "configuring slave " << i << "..." << std::endl;
            slave_base_arr[i]->config_slave(master);
        }
    }

    void create_pdo_config()
    {
        std::cout << "configuring pdos..." << std::endl;
        for (int i = 0; i < num_slaves; i++)
        {
            std::cout << "configuring pdos for slave " << i << "..." << std::endl;
            slave_base_arr[i]->config_pdo();
        }
    }

    void register_pdo_group()
    {
        std::cout << "registering pdos..." << std::endl;
        for (int i = 0; i < num_slaves; i++)
        {
            std::cout << "registering pdos for slave " << i << "..." << std::endl;
            slave_base_arr[i]->register_pdo_group(domain_1);
        }
    }

    bool activate()
    {
        if (!ecrt_master_activate(master))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool get_domain_process_data()
    {
        domain_1_pd = ecrt_domain_data(domain_1);
        if (domain_1_pd)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void set_domain_process_data()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->set_domain(domain_1_pd);
        }
    }

    // 4. Monitor status
    void monitor_status()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->monitor_status();
        }
    }

    // 5. Transfer tx_pdo
    void transfer_tx_pdo()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->transfer_tx_pdo();
        }
    }

    // 6. Process tx_pdo
    void process_tx_pdo()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->process_tx_pdo();
        }
    }

    // 7. Publish tx_pdo data
    void publish_data()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->publish_data();
        }
    }

    // 8. Subscribe rx_pdo data
    void subscribe_data()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->subscribe_data();
        }
    }

    // 9. Process rx_pdo data
    void process_rx_pdo()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->process_rx_pdo();
        }
    }

    // 10. Transfer rx_pdo
    void transfer_rx_pdo()
    {
        for (int i = 0; i < num_slaves; i++)
        {
            slave_base_arr[i]->transfer_rx_pdo();
        }
    }
};

#endif // ETHERCAT_MASTER_BASE_H
