/**
 * @file earth_utils.h
 * @brief Handles the declaration of google earth utility functions
 * @author Julien Marcuse
 * @assignment Lab 10.2
 * @date 11/9/2020
*/

#ifndef CSI230LAB10_2_EARTH_UTILS_H
#define CSI230LAB10_2_EARTH_UTILS_H

#include <fstream>

/**
 * @brief Converts a CSV file to a KML file
 * @param in The input file
 * @param out The output file
 * @return The number of lines written
 */
int convert(std::ifstream& in, std::ofstream& out);


#endif //CSI230LAB10_2_EARTH_UTILS_H
