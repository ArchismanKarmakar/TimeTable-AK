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

#include "./../include/login.h"
#include "./../include/signup.h"
#include "./../include/table_manage.h"

// #define cls() system("cls");
// #define swap(a, b) do { typeof(a) temp = a; a = b; b = temp; } while (0)

#define cls() cout << "\033[2J\033[1;1H";

#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                         \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

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
                    pause();
                }

                // After Login operations to be added

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
                        pause();
                    }
                }
            }
            break;
        }
        case 2:
        {
            cout << "Enter Username: ";
            string uname;
            cin >> uname;
            string funame = uname + ".dat";
            if (std::filesystem::exists(funame))
            {
                cout << "File already exists. Please Login." << endl;
                pause();
                break;
            }
            EncryptPass ep(uname);
            if (ep.createUser())
            {
                cout << "File created successfully. You can now login." << endl;
                pause();
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
            pause();
            break;
        }
        }
    }
    return EXIT_SUCCESS;
}