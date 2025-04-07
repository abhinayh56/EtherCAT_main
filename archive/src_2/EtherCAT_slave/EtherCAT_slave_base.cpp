#include "EtherCAT_slave_base.h"

void EtherCAT_slave_base::set_slave_name(const std::string &slave_name_)
{
    slave_name = slave_name_;
}

std::string &EtherCAT_slave_bas::get_slave_name() const
{
    return slave_name;
}

void EtherCAT_slave_base::set_slave_address(const uint16_t slave_address_)
{
    slave_address = slave_address_;
}

uint16_t EtherCAT_slave_base::get_slave_address() const
{
    return slave_address;
}

void EtherCAT_slave_base::set_slave_info()
{
}

void EtherCAT_slave_base::get_slave_info()
{
}

void EtherCAT_slave_base::config_slave(ec_master_t *master)
{
    // set_slave_name(const std::string &slave_name_)
    // set_slave_address(const uint16_t slave_address_)
    // uint16_t alias = 0;
    // uint16_t position = 9;
    // uint32_t vendor_id = 0x00113322;
    // uint32_t product_code = 0x00001022;
    // connection_status = false
}

bool EtherCAT_slave_base::is_connected()
{
    return connection_status;
}

void EtherCAT_slave_base::monitor_status()
{
}

void EtherCAT_slave_base::transfer_tx_pdo()
{
}

void EtherCAT_slave_base::transfer_rx_pdo()
{
}