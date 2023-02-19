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

#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                          \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

class DecryptPass
{
public:
    bool securityChk();
    DecryptPass(std::string uname)
    {
        username = uname;
    }

private:
    std::string username;
};