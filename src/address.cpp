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

#include "./../include/address.hh"

using namespace std;

Address::Address()
{
    line1 = "";
    line2 = "";
    city = "";
    state = "";
    pinCode = "";
    country = "";
}
void Address::takeInput()
{
    cout << "\nEnter address:\n";
    cout << "\nLine 1:\n";
    getline(cin >> ws, line1);
    cout << "\nLine 2 (optional):\n";
    getline(cin, line2);
    cout << "\nCity:\n";
    getline(cin >> ws, city);
    cout << "\nState:\n";
    getline(cin >> ws, state);
    cout << "\nPin Code:\n";
    getline(cin >> ws, pinCode);
    cout << "\nCountry:\n";
    getline(cin >> ws, country);
    return;
}
void Address::print()
{
    cout << "Line 1: " << line1 << "\n";
    if (line2 != "")
        cout << "                  "
             << "Line 2: " << line2 << "\n";
    cout << "                  ";
    cout << "City: " << city << "\n";
    cout << "                  ";
    cout << "State: " << state << "\n";
    cout << "                  ";
    cout << "Pin Code: " << pinCode << "\n";
    cout << "                  ";
    cout << "Country: " << country << "\n";
    return;
}
string Address::addToStr()
{
    stringstream s;
    s << line1 << "`" << line2 << "`" << city << "`" << state << "`" << pinCode << "`" << country;
    string addable;
    getline(s, addable);
    for (auto &i : addable)
        if (i == ',')
            i = '^';
    return addable;
}
void Address::strToAdd(string str)
{
    stringstream s(str);

    getline(s, line1, '`');
    for (auto &i : line1)
        if (i == '^')
            i = ',';

    getline(s, line2, '`');
    for (auto &i : line2)
        if (i == '^')
            i = ',';

    getline(s, city, '`');
    getline(s, state, '`');
    getline(s, pinCode, '`');
    getline(s, country, '`');
    return;
}