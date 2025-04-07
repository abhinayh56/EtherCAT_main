#ifndef ETHERCAT_SLAVE_1_H
#define ETHERCAT_SLAVE_1_H

#include <ecrt.h>
#include "EtherCAT_slave_base.h"
#include <iostream>

class EtherCAT_slave_1 : public EtherCAT_slave_base
{
public:
    EtherCAT_slave_1() {}

    ~EtherCAT_slave_1() {}

    void config_slave(ec_master_t *master)
    {
        if (!(sc = ecrt_master_slave_config(master, alias, position, vendor_id, product_code)))
        {
            std::cout << "configuring failed for slaves " << std::endl;
        }
        else
        {
            std::cout << "configuring done for slaves " << std::endl;
        }
    }

    void config_pdo()
    {
        if (ecrt_slave_config_pdos(sc, EC_END, slave_syncs))
        {
            std::cout << "configuring pdo failed for slave " << std::endl;
        }
        else
        {
            std::cout << "configuring pdo done for slave " << std::endl;
        }
    }

    void register_pdo_group(ec_domain_t *domain)
    {
        if (ecrt_domain_reg_pdo_entry_list(domain, domain_regs))
        {
            fprintf(stderr, "PDO entry registration failed!\n");
        }
        else
        {
            std::cout << "PDO entry in domain successful" << std::endl;
        }
    }

    void read_pdo()
    {
        uint16_t Device_ID = EC_READ_U16(domain_1_pd + off_1);
        uint16_t Second = EC_READ_U16(domain_1_pd + off_2);
        uint16_t Minute = EC_READ_U16(domain_1_pd + off_3);
        uint16_t Hour = EC_READ_U16(domain_1_pd + off_4);
        uint16_t Day = EC_READ_U16(domain_1_pd + off_5);
        uint16_t Month = EC_READ_U16(domain_1_pd + off_6);
        uint16_t Year = EC_READ_U16(domain_1_pd + off_7);
        uint16_t Roll_Offset = EC_READ_U16(domain_1_pd + off_8);
        uint16_t Pitch_Offset = EC_READ_U16(domain_1_pd + off_9);
        uint16_t Yaw_Offset = EC_READ_U16(domain_1_pd + off_10);
        uint16_t Grip_Offset = EC_READ_U16(domain_1_pd + off_11);
        uint16_t No_of_Usages = EC_READ_U16(domain_1_pd + off_12);
        uint16_t Max_Usages = EC_READ_U16(domain_1_pd + off_13);
        uint16_t Digital_Inputs = EC_READ_U16(domain_1_pd + off_14);
        uint16_t Grip_Counts = EC_READ_U16(domain_1_pd + off_15);
        uint16_t System_Number = EC_READ_U16(domain_1_pd + off_16);
        uint16_t Device_UID = EC_READ_U16(domain_1_pd + off_17);
        uint16_t Spare_Bytes = EC_READ_U16(domain_1_pd + off_18);
        uint16_t MFG_Day = EC_READ_U16(domain_1_pd + off_19);
        uint16_t MFG_Month = EC_READ_U16(domain_1_pd + off_20);
        uint16_t MFG_Year = EC_READ_U16(domain_1_pd + off_21);

        std::cout << "TXPDO_1: " << Device_ID << ", " << Second << ", " << Minute << ", " << Hour << ", " << Day << ", " << Month << ", " << Year << ", " << Roll_Offset << ", " << Pitch_Offset << ", " << Yaw_Offset << ", " << Grip_Offset << ", " << No_of_Usages << ", " << Max_Usages << ", " << Digital_Inputs << ", " << Grip_Counts << ", " << System_Number << ", " << Device_UID << ", " << Spare_Bytes << ", " << MFG_Day << ", " << MFG_Month << ", " << MFG_Year << std::endl;
    }

    void set_domain(uint8_t *domain_1_pd_)
    {
        domain_1_pd = domain_1_pd_;
    }

private:
    ec_slave_config_t *sc;
    ec_slave_config_state_t sc_state;
    uint8_t *domain_1_pd = NULL;

    uint16_t alias = 0;
    uint16_t position = 7;
    uint32_t vendor_id = 0x00006000;
    uint32_t product_code = 0x00004000;

    const ec_pdo_entry_info_t slave_pdo_entries[40] = {
        {0x0005, 0x01, 16}, /* Acknowledge */
        {0x0005, 0x02, 16}, /* Second */
        {0x0005, 0x03, 16}, /* Minute */
        {0x0005, 0x04, 16}, /* Hour */
        {0x0005, 0x05, 16}, /* Day */
        {0x0005, 0x06, 16}, /* Month */
        {0x0005, 0x07, 16}, /* Year */
        {0x0005, 0x08, 16}, /* No_of_Usages */
        {0x0005, 0x09, 16}, /* Digital_Outputs */
        {0x0005, 0x0a, 16}, /* Grip_Counts */
        {0x0005, 0x0b, 16}, /* System_Number */
        {0x0005, 0x0c, 16}, /* Led_Red */
        {0x0005, 0x0d, 16}, /* Led_Green */
        {0x0005, 0x0e, 16}, /* Led_Blue */
        {0x0005, 0x0f, 16}, /* Spare_Bytes */
        {0x0005, 0x10, 16}, /* Roll_Offset */
        {0x0005, 0x11, 16}, /* Pitch_Offset */
        {0x0005, 0x12, 16}, /* Yaw_Offset */
        {0x0005, 0x13, 16}, /* Grip_Offset */
        {0x0006, 0x01, 16}, /* Device_ID */
        {0x0006, 0x02, 16}, /* Second */
        {0x0006, 0x03, 16}, /* Minute */
        {0x0006, 0x04, 16}, /* Hour */
        {0x0006, 0x05, 16}, /* Day */
        {0x0006, 0x06, 16}, /* Month */
        {0x0006, 0x07, 16}, /* Year */
        {0x0006, 0x08, 16}, /* Roll_Offset */
        {0x0006, 0x09, 16}, /* Pitch_Offset */
        {0x0006, 0x0a, 16}, /* Yaw_Offset */
        {0x0006, 0x0b, 16}, /* Grip_Offset */
        {0x0006, 0x0c, 16}, /* No_of_Usages */
        {0x0006, 0x0d, 16}, /* Max_Usages */
        {0x0006, 0x0e, 16}, /* Digital_Inputs */
        {0x0006, 0x0f, 16}, /* Grip_Counts */
        {0x0006, 0x10, 16}, /* System_Number */
        {0x0006, 0x11, 16}, /* Device_UID */
        {0x0006, 0x12, 16}, /* Spare_Bytes */
        {0x0006, 0x13, 16}, /* MFG_Day */
        {0x0006, 0x14, 16}, /* MFG_Month */
        {0x0006, 0x15, 16}, /* MFG_Year */
    };

    const ec_pdo_info_t slave_pdos[2] = {
        {0x1600, 19, slave_pdo_entries + 0},  /* Outputs */
        {0x1a00, 21, slave_pdo_entries + 19}, /* Inputs */
    };

    const ec_sync_info_t slave_syncs[3] = {
        {0, EC_DIR_OUTPUT, 1, slave_pdos + 0, EC_WD_ENABLE},
        {1, EC_DIR_INPUT, 1, slave_pdos + 1, EC_WD_DISABLE},
        {0xff}};

    unsigned int off_1;
    unsigned int off_2;
    unsigned int off_3;
    unsigned int off_4;
    unsigned int off_5;
    unsigned int off_6;
    unsigned int off_7;
    unsigned int off_8;
    unsigned int off_9;
    unsigned int off_10;
    unsigned int off_11;
    unsigned int off_12;
    unsigned int off_13;
    unsigned int off_14;
    unsigned int off_15;
    unsigned int off_16;
    unsigned int off_17;
    unsigned int off_18;
    unsigned int off_19;
    unsigned int off_20;
    unsigned int off_21;

    const ec_pdo_entry_reg_t domain_regs[22] = {
        {alias, position, vendor_id, product_code, 0x0006, 0x01, &off_1},
        {alias, position, vendor_id, product_code, 0x0006, 0x02, &off_2},
        {alias, position, vendor_id, product_code, 0x0006, 0x03, &off_3},
        {alias, position, vendor_id, product_code, 0x0006, 0x04, &off_4},
        {alias, position, vendor_id, product_code, 0x0006, 0x05, &off_5},
        {alias, position, vendor_id, product_code, 0x0006, 0x06, &off_6},
        {alias, position, vendor_id, product_code, 0x0006, 0x07, &off_7},
        {alias, position, vendor_id, product_code, 0x0006, 0x08, &off_8},
        {alias, position, vendor_id, product_code, 0x0006, 0x09, &off_9},
        {alias, position, vendor_id, product_code, 0x0006, 0x0a, &off_10},
        {alias, position, vendor_id, product_code, 0x0006, 0x0b, &off_11},
        {alias, position, vendor_id, product_code, 0x0006, 0x0c, &off_12},
        {alias, position, vendor_id, product_code, 0x0006, 0x0d, &off_13},
        {alias, position, vendor_id, product_code, 0x0006, 0x0e, &off_14},
        {alias, position, vendor_id, product_code, 0x0006, 0x0f, &off_15},
        {alias, position, vendor_id, product_code, 0x0006, 0x10, &off_16},
        {alias, position, vendor_id, product_code, 0x0006, 0x11, &off_17},
        {alias, position, vendor_id, product_code, 0x0006, 0x12, &off_18},
        {alias, position, vendor_id, product_code, 0x0006, 0x13, &off_19},
        {alias, position, vendor_id, product_code, 0x0006, 0x14, &off_20},
        {alias, position, vendor_id, product_code, 0x0006, 0x15, &off_21},
        {}};
};

#endif // ETHERCAT_SLAVE_1_H
