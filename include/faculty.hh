#ifndef FACULTY
#define FACULTY
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
#include <./../include/global.hh>

using namespace std;

class Faculty // ABSTRACT CLASS
{
protected:
    string id;
    string name;
    int16_t age;
    string phone;
    string email;
    char gender;

public:
    Faculty();
    void addFaculty(int16_t minAge = 18, int16_t maxAge = 100);
    void removeFaculty();
    void editMap();
    void fillMap();
};

#endif