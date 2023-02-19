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

#include "signup.hh"
#include <./../include/global.hh>

using namespace std;
namespace fs = std::filesystem;

bool EncryptPass::createUser()
{
    try
    {
        string funame = username + ".dat";
        if (std::filesystem::exists(funame))
        {
            cout << "File Already Exists." << endl;
            return false;
        }
        string pass;
        ofstream file(funame, ios::out | ios::in);
        cout << "Password must be exactly 8 characters long only." << endl;
        cout << "Enter new password: ";
        cin >> pass;
        file.write((char *)pass.c_str(), sizeof(pass));
        file.close();
        if (file.good())
        {
            return true;
        }
        else
        {
            cout << "Error occurred while creating file." << endl;
            pause();
            return false;
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