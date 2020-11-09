/**
 * @file main.cpp
 * @brief Converts a CSV file of country data to a KML file that can be imported using google maps
 * @author Julien Marcuse
 * @assignment Lab 10.2
 * @date 11/9/2020
*/

#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <fstream>
#include "logger.h"
#include "earth_utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    int opt = -1;
    string kmlValue = "";
    string logValue = "";
    string pname = basename(argv[0]);
    while ((opt = getopt(argc, argv, "k:l:")) != EOF) {
        switch (opt) {
            case 'k':
                kmlValue = optarg;
                break;
            case 'l':
                logValue = optarg;
                break;
            default:
                cout << "Invalid flag " << char(opt) << endl;
                return 1;
        }
    }
    if (kmlValue.empty() || logValue.empty()) {
        cout << "Must pass -k and -l flags" << endl;
        return 1;
    }
    ofstream flog;
    flog.open(logValue, ios::app);
    if (!flog.is_open()) {
        cout << "Could not open log file" << endl;
        return 1;
    }
    string msg = "The KML file is: " + kmlValue + " and the logfile is: " + logValue;
    log(msg, pname, flog);
    flog.close();
    ifstream fin(kmlValue);
    ofstream fout(kmlValue + ".kml");
    int converted = convert(fin, fout);
    cout << "Converted " << converted << " locations." << endl;
    return 0;
}
