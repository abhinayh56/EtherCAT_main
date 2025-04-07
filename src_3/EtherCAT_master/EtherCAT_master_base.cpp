#include "EtherCAT_master_base.h"

EtherCAT_master_base::EtherCAT_master_base() {}

EtherCAT_master_base::~EtherCAT_master_base() {}

void EtherCAT_master_base::add_slave(EtherCAT_slave_base *new_slave)
{
    slave_base_arr.push_back(new_slave);
    num_slaves = slave_base_arr.size();
}

void EtherCAT_master_base::config()
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

void EtherCAT_master_base::cyclic_task()
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

bool EtherCAT_master_base::start()
{
    LOG_CONSOLE_INFO("Creating master...", 1);

    master = ecrt_request_master(0);
    if (master)
    {
        LOG_CONSOLE_INFO("Master creation successful", 1);
        return true;
    }
    else
    {
        LOG_CONSOLE_ERROR("Master creation failed", 1);
        return false;
    }
}

bool EtherCAT_master_base::stop()
{
    LOG_CONSOLE_INFO("Stopping master...", 1);
    ecrt_release_master(master);
    LOG_CONSOLE_INFO("Master stopped", 1);
    return true;
}

bool EtherCAT_master_base::create_domain()
{
    LOG_CONSOLE_INFO("Creating domain...", 1);
    domain_1 = ecrt_master_create_domain(master);
    if (domain_1)
    {
        LOG_CONSOLE_INFO("Domain creation successful", 1);
        return true;
    }
    else
    {
        LOG_CONSOLE_ERROR("Domain creation failed, 1")
        return false;
    }
}

void EtherCAT_master_base::configure_slaves()
{
    LOG_CONSOLE_INFO("Configuring slaves...", 1);
    for (int i = 0; i < num_slaves; i++)
    {
        LOG_CONSOLE_INFO("Configuring slave ", 0);
        LOG_CONSOLE_INFO(i, 0);
        LOG_CONSOLE_INFO(" of ", 0);
        LOG_CONSOLE_INFO(num_slaves, 1);
        slave_base_arr[i]->config_slave(master);
    }
    LOG_CONSOLE_INFO("Configured all slaves", 1);
}

void EtherCAT_master_base::create_pdo_config()
{
    LOG_CONSOLE_INFO("Configuring pdos...", 1);
    for (int i = 0; i < num_slaves; i++)
    {
        LOG_CONSOLE_INFO("Configuring pdos of slave ", 0);
        LOG_CONSOLE_INFO(i, 0);
        LOG_CONSOLE_INFO(" of ", 0);
        LOG_CONSOLE_INFO(num_slaves, 1);
        slave_base_arr[i]->config_pdo();
    }
    LOG_CONSOLE_INFO("Configured all pdos", 1);
}

void EtherCAT_master_base::register_pdo_group()
{
    LOG_CONSOLE_INFO("Registering pdos", 1);
    for (int i = 0; i < num_slaves; i++)
    {
        LOG_CONSOLE_INFO("Registering pdos for slave ", 0);
        LOG_CONSOLE_INFO(i, 0);
        LOG_CONSOLE_INFO(" of ", 0);
        LOG_CONSOLE_INFO(num_slaves, 1);
        slave_base_arr[i]->register_pdo_group(domain_1);
    }
    LOG_CONSOLE_INFO("Registered all pdos", 1);
}

bool EtherCAT_master_base::activate()
{
    LOG_CONSOLE_INFO("Activating master...", 1);
    if (!ecrt_master_activate(master))
    {
        LOG_CONSOLE_INFO("Master activated successfully", 1);
        return true;
    }
    else
    {
        LOG_CONSOLE_ERROR("Failed to activate master", 1);
        return false;
    }
}

bool EtherCAT_master_base::get_domain_process_data()
{
    LOG_CONSOLE_INFO("Getting pointer to domain process data...", 1);
    domain_1_pd = ecrt_domain_data(domain_1);
    if (domain_1_pd)
    {
        LOG_CONSOLE_INFO("Domain process data pointer get successful", 1);
        return true;
    }
    else
    {
        LOG_CONSOLE_ERROR("Failed to get domain process data pointer", 1);
        return false;
    }
}

void EtherCAT_master_base::set_domain_process_data()
{
    LOG_CONSOLE_INFO("Providing pointer to domain process data...", 1);
    for (int i = 0; i < num_slaves; i++)
    {
        LOG_CONSOLE_INFO("Providing pointer to domain process data to slave ", 0);
        LOG_CONSOLE_INFO(i, 0);
        LOG_CONSOLE_INFO(" of ", 0);
        LOG_CONSOLE_INFO(num_slaves, 1);
        slave_base_arr[i]->set_domain(domain_1_pd);
    }
}

void EtherCAT_master_base::monitor_status()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->monitor_status();
    }
}

void EtherCAT_master_base::transfer_tx_pdo()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->transfer_tx_pdo();
    }
}

void EtherCAT_master_base::process_tx_pdo()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->process_tx_pdo();
    }
}

void EtherCAT_master_base::publish_data()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->publish_data();
    }
}

void EtherCAT_master_base::subscribe_data()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->subscribe_data();
    }
}

void EtherCAT_master_base::process_rx_pdo()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->process_rx_pdo();
    }
}

void EtherCAT_master_base::transfer_rx_pdo()
{
    for (int i = 0; i < num_slaves; i++)
    {
        slave_base_arr[i]->transfer_rx_pdo();
    }
}