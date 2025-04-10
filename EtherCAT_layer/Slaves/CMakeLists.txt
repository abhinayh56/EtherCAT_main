add_library(ethercat_slaves
    EtherCAT_slave_1.cpp
    EtherCAT_slave_2.cpp
)

target_include_directories(ethercat_slaves PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set the path to the EtherCAT library and specify the library
set(EtherCAT_LIB_PATH /usr/local/etherlab/lib/libethercat.so)

# Depends on slave base
target_link_libraries(ethercat_slaves PUBLIC ${EtherCAT_LIB_PATH} ethercat_slave_base)
