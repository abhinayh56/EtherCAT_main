cmake_minimum_required(VERSION 3.5)
project(EtherCAT_main)

# Set include directories for EtherCAT headers
include_directories(
    /usr/local/etherlab/include  # Path to the ecrt.h header
)

# Set the path to the EtherCAT library and specify the library
set(EtherCAT_LIB_PATH /usr/local/etherlab/lib/libethercat.so)

# Create the executable from the source code
add_executable(EtherCAT_main src/EtherCAT_main.cpp)

# Link against the EtherCAT library
target_link_libraries(EtherCAT_main ${EtherCAT_LIB_PATH})
