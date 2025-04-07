#ifndef LOGGER_CONSOLE_H
#define LOGGER_CONSOLE_H

#include <iostream>

#define LOG_CONSOLE_INFO(msg)    std::cout << "INFO   : " << msg << std::endl
#define LOG_CONSOLE_ERROR(msg)   std::cout << "ERROR  : " << msg << std::endl
#define LOG_CONSOLE_WARNING(msg) std::cout << "WARNING: " << msg << std::endl

#endif LOGGER_CONSOLE_H
