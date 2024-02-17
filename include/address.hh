#ifndef ADDRESS
#define ADDRESS

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

class Address
{
private:
    string line1, line2;
    string city;
    string state;
    string pinCode;
    string country;

public:
    Address();
    void takeInput();
    void print();
    string addToStr();
    void strToAdd(string str);
};

#endif