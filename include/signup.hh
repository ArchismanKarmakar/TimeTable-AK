#ifndef SIGNUP
#define SIGNUP
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

class EncryptPass
{
public:
    bool createUser();
    EncryptPass(std::string uname)
    {
        username = uname;
    }

private:
    std::string username;
};
#endif