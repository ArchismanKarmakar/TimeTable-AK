#ifndef GLOBAL
#define GLOBAL
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

void pause()
{
    do
    {
        cout << "\n";
    } while (cin.get() != '\n');
    do
    {
        cout << "Press a key to continue...";
    } while (cin.get() != '\n');
}

int power(int n, int exp)
{
    int res = 1;
    while (exp)
    {
        if (exp & 1)
            res *= n, exp--;
        else
            n *= n, exp >>= 1;
    }
    return res;
}

int strToNum(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += ((s[s.size() - 1 - i] - '0') * power(10, i));
    return res;
}

#endif