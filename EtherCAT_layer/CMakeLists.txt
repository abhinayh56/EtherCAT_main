cmake_minimum_required(VERSION 3.10)
project(EtherCAT_layer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(Slaves)

# Create executable from main file
add_executable(EtherCAT_layer EtherCAT_layer.cpp)

# Set the path to the EtherCAT library and specify the library
set(EtherCAT_LIB_PATH /usr/local/etherlab/lib/libethercat.so)

# Link all submodules
target_link_libraries(EtherCAT_layer
    PRIVATE
        ${EtherCAT_LIB_PATH}
        ethercat_slaves
        ethercat_master
        ethercat_slave_base        
)

# Set include directories for EtherCAT headers
include_directories(
    /usr/local/etherlab/include  # Path to the ecrt.h header
)
