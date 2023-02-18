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

#include "login.h"
#include "signup.h"
#include "table_manage.h"

using namespace std;

int TimeTable::getDay()
{
    return day;
}

void TimeTable::setDay(int day)
{
    this->day = day;
}

void Period::openFileChk(string uname)
{
    string funame = uname + ".dat";
    if (std::filesystem::exists(funame))
    {
        ifstream file(funame, ios::out | ios::binary);
        file.close();
    }
}

void TimeTable::displayRoutine(std::string uname)
{
    string funame = uname + ".dat";
    if (std::filesystem::exists(funame))
    {
        TimeTable period[7];
        ifstream file(funame, ios::out | ios::binary);
        file.seekg(9, ios::beg);
        for (int i = 0; i < 8; i++)
        {
            if (!file.eof())
            {
                file.read((char *)&period[i], sizeof(Period));
                setDay(i + 1);
            }
        }

        file.close();
    }
}