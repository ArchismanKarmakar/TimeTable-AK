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

#include <signup.h>

using namespace std;
namespace fs = std::filesystem;

bool EncryptPass::createUser()
{
    try
    {
        string funame = username + ".dat";
        ofstream MyFile(funame, ios::out | ios::binary);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return false;
}