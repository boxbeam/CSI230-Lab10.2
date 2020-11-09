/**
 * @file logger.h
 * @brief Handles the declaration of logging functionality
 * @author Julien Marcuse
 * @assignment Lab 10.2
 * @date 11/9/2020
 */

#ifndef CSI230LAB10_2_LOGGER_H
#define CSI230LAB10_2_LOGGER_H

#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <iostream>

/**
 * @brief Creates a discrete syslog message
 * @date 11/9/2020
 * @return True if the log was written, false otherwise
 * @param msg std::string containing syslog messages
 * @logFile ofstream reference, validation of this file is expected
 */
 bool log(std::string msg, std::string programName, std::ofstream& logFile);

#endif