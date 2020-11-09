/**
 * @file earth_utils.cpp
 * @brief Handles the implementation of google earth utility functions
 * @author Julien Marcuse
 * @assignment Lab 10.2
 * @date 11/9/2020
*/

#include "earth_utils.h"

using namespace std;

void write(ofstream& out, string& country, string& capital, string& latitude, string& longitude) {
    out << "<Placemark>" << endl;
    out << "<name>" << capital << ", " << country << "</name>" << endl;
    out << "<Point><coordinates>" << longitude << ", " << latitude << "</coordinates></Point>" << endl;
    out << "</Placemark>" << endl;
}

int convert(ifstream& in, ofstream& out) {
    string info;
    getline(in, info);
    string country;
    string capital;
    string longitude;
    string latitude;
    out << R"(<?xml version="1.0" encoding="UTF-8"?>)" << endl;
    out << R"(<kml xmlns="http://www.opengis.net/kml/2.2" xmlns:gx="http://www.google.com/kml/ext/2.2" xmlns:kml="http://www.opengis.net/kml/2.2" xmlns:atom="http://www.w3.org/2005/Atom">)" << endl;
    out << "<Document>" << endl;
    int lines = 0;
    while (!in.eof()) {
        getline(in, country, ',');
        getline(in, capital, ',');
        getline(in, latitude, ',');
        getline(in, longitude, ',');
        getline(in, info);
        write(out, country, capital, latitude, longitude);
        lines++;
    }
    out << "</Document>" << endl;
    out << "</kml>" << endl;
    return lines;
}