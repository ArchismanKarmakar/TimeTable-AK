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

#include "./../include/login.hh"
#include "./../include/signup.hh"
#include "./../include/table_manage.hh"

using namespace std;

// int TimeTable::getDay()
// {
//     return day;
// }

// void TimeTable::setDay(int day)
// {
//     this->day = day;
// }

void Period::openFileChk(string uname)
{
    string funame = uname + ".dat";
    if (std::filesystem::exists(funame))
    {
        ifstream file(funame, ios::out | ios::in);
        file.close();
    }
}

void displayRoutine(std::string uname)
{
    string funame = uname + ".dat";
    if (std::filesystem::exists(funame))
    {
        vector<Period> period(25);
        ifstream file(funame, ios::out | ios::in);
        file.seekg(9, ios::beg);
        int i = -1;
        while (!file.eof())
        {
            file.read((char *)&period[++i], sizeof(Period));
            // setDay(i + 1);
        }
        file.close();
    }
}