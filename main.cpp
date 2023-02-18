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

#include <login.h>
#include <signup.h>

#define cls() system("cls");

using namespace std;
namespace fs = std::filesystem;

int main()
{
    int choice;
    while (1)
    {
        cls();
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Username: ";
            string uname;
            cin >> uname;
            string funame = uname + ".dat";
            if (std::filesystem::exists(funame))
            {
                DecryptPass dp(uname);
                if (dp.securityChk())
                {
                    cout << "Login Successful." << endl;
                }
            }
            else
            {
                cout << "File not found. Create new file? y/n" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    EncryptPass ep(uname);
                    if (ep.createUser())
                    {
                        cout << "File created successfully. You can now login." << endl;
                    }
                }
            }
            break;
        }
        case2:
        {
            cout << "Enter Username: ";
            string uname;
            cin >> uname;
            string funame = uname + ".dat";
            if (std::filesystem::exists(funame))
            {
                cout << "File already exists. Please Login." << endl;
                break;
            }
            EncryptPass ep(uname);
            if (ep.createUser())
            {
                cout << "File created successfully. You can now login." << endl;
            }
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }
    return EXIT_SUCCESS;
}