#ifndef TABLE_MANAGE
#define TABLE_MANAGE

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace std;

#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                         \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

// class TimeTable
// {
// public:
//     int getDay();
//     void setDay(int day);
//     void displayRoutine(std::string uname);

// private:
//     int day = 0;
// };

class Period
{
public:
    void periodConstructor(int periodNo, int startTime, int endTime, std::string facultyId, std::string subId, int day, int totalPeriods)
    {
        this->periodNo = periodNo;
        this->startTime = startTime;
        this->endTime = endTime;
        this->facultyId = facultyId;
        this->subId = subId;
    }
    void openFileChk(std::string uname);

private:
    int periodNo;
    int startTime;
    int endTime;
    std::string facultyId;
    std::string subId;
};

#endif