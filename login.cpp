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

using namespace std;
namespace fs = std::filesystem;

bool DecryptPass::securityChk()
{
    try
    {
        string funame = username + ".dat";
        if (std::filesystem::exists(funame))
        {
            string pass;
            string passmat;
            fstream file;
            cout << "Enter password: ";
            cin >> pass;
            file.open(username + ".dat", ios::out | ios::binary);
            getline(file, passmat);
            if (passmat.compare(pass) == 0)
            {
                file.close();
                return true;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        getchar();
        return false;
    }
    return false;
}