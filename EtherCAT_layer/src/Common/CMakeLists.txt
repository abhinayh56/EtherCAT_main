# Common does not build anything, just header-only
add_library(ethercat_common INTERFACE)

target_include_directories(ethercat_common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
