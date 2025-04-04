#ifndef DATA_TRANSFER_H
#define DATA_TRANSFER_H

class Data_transfer
{
public:
    virtual void config_data_transfer() {}

    virtual void publish_data() {}

    virtual void subscribe_data() {}
};

#endif // DATA_TRANSFER_H
