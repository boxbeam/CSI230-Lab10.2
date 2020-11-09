/**
 * @file logger.cpp
 * @brief Handles the implementation of logging functionality
 * @author Julien Marcuse
 * @assignment Lab 10.2
 * @date 11/9/2020
*/

#include "logger.h"

using namespace std;

bool log(string msg, string programName, ofstream& logFile) {
    string strTime;
    cout << programName << endl;
    //get the time
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    //time of the newline
    int timeSize = strTime.size();
    if (timeSize) {
        strTime[timeSize - 1] = ' ';
    }

    char* hostName = new char[20];
    gethostname(hostName, 20);
    int pid = getpid();

    if (logFile) {
        logFile << strTime << hostName << " " << programName << "[" << pid << "]: " << msg << endl;
        return true;
    }
    return false;
}