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
            char *passmat;
            cout << "Enter password: ";
            cin >> pass;
            ifstream file(username + ".dat", ios::out | ios::binary);
            // getline(file, passmat);
            file.read(passmat, sizeof(pass));
            cout << string(passmat) << endl;
            file.close();
            if (string(passmat).compare(pass) == 0)
            {
                return true;
            }
            else
            {
                cout << "Password does not match." << endl;
                pause();
                return false;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        pause();
        return false;
    }
    return false;
}