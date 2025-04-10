add_library(ethercat_master
    EtherCAT_master.cpp
)

target_include_directories(ethercat_master PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set the path to the EtherCAT library and specify the library
set(EtherCAT_LIB_PATH /usr/local/etherlab/lib/libethercat.so)

# Link common utilities
target_link_libraries(ethercat_master PUBLIC ${EtherCAT_LIB_PATH} ethercat_common)
