#ifndef ETHERCAT_SLAVE_2_H
#define ETHERCAT_SLAVE_2_H

#include <ecrt.h>
#include "EtherCAT_slave_base.h"
#include <iostream>

class EtherCAT_slave_2 : public EtherCAT_slave_base
{
public:
    EtherCAT_slave_2() {}

    ~EtherCAT_slave_2() {}

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
        int32_t ACT_POS = EC_READ_S32(domain_1_pd + off_1);
        uint16_t STATUS_WD = EC_READ_U16(domain_1_pd + off_2);
        int16_t ACT_TOR = EC_READ_S16(domain_1_pd + off_3);
        uint8_t OPMODE_DISP = EC_READ_U8(domain_1_pd + off_4);
        uint16_t ERROR_CODE = EC_READ_U16(domain_1_pd + off_5);
        uint8_t DIG_IN = EC_READ_U8(domain_1_pd + off_6);
        int32_t ACT_VEL = EC_READ_S32(domain_1_pd + off_7);
        int16_t ADC_VAL = EC_READ_S16(domain_1_pd + off_8);

        std::cout << "TXPDO_2: " << ACT_POS << ", " << STATUS_WD << ", " << ACT_TOR << ", " << OPMODE_DISP << ", " << ERROR_CODE << ", " << DIG_IN << ", " << ACT_VEL << ", " << ADC_VAL << std::endl;
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
    uint16_t position = 8;
    uint32_t vendor_id = 0x00113322;
    uint32_t product_code = 0x00001022;

    const ec_pdo_entry_info_t slave_pdo_entries[15] = {
        {0x607a, 0x00, 32}, /* TARGET_POS */
        {0x6040, 0x00, 16}, /* CONTROL_WD */
        {0x6071, 0x00, 16}, /* TARGET_TORQ */
        {0x6060, 0x00, 8},  /* OP_MODE */
        {0x3004, 0x00, 16}, /* ERROR_CLEAR */
        {0x3001, 0x00, 8},  /* DIG_OUT */
        {0x60ff, 0x00, 32}, /* TARGET_VEL */
        {0x6064, 0x00, 32}, /* ACT_POS */
        {0x6041, 0x00, 16}, /* STATUS_WD */
        {0x6077, 0x00, 16}, /* ACT_TOR */
        {0x6061, 0x00, 8},  /* OPMODE_DISP */
        {0x603f, 0x00, 16}, /* ERROR_CODE */
        {0x3002, 0x00, 8},  /* DIG_IN */
        {0x606c, 0x00, 32}, /* ACT_VEL */
        {0x3007, 0x00, 16}, /* ADC_VAL */
    };

    const ec_pdo_info_t slave_pdos[2] = {
        {0x1600, 7, slave_pdo_entries + 0}, /* Outputs */
        {0x1a00, 8, slave_pdo_entries + 7}, /* Inputs */
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

    const ec_pdo_entry_reg_t domain_regs[22] = {
        {alias, position, vendor_id, product_code, 0x6064, 0x00, &off_1}, /* ACT_POS */
        {alias, position, vendor_id, product_code, 0x6041, 0x00, &off_2}, /* STATUS_WD */
        {alias, position, vendor_id, product_code, 0x6077, 0x00, &off_3}, /* ACT_TOR */
        {alias, position, vendor_id, product_code, 0x6061, 0x00, &off_4}, /* OPMODE_DISP */
        {alias, position, vendor_id, product_code, 0x603f, 0x00, &off_5}, /* ERROR_CODE */
        {alias, position, vendor_id, product_code, 0x3002, 0x00, &off_6}, /* DIG_IN */
        {alias, position, vendor_id, product_code, 0x606c, 0x00, &off_7}, /* ACT_VEL */
        {alias, position, vendor_id, product_code, 0x3007, 0x00, &off_8}, /* ADC_VAL */
        {}};
};

#endif // ETHERCAT_SLAVE_2_H
