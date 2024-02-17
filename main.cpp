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

#include "./include/table_manage.hh"

using namespace std;

void viewRoutine();

int main()
{
    cout << "Routine Management System" << endl;
    cout << "1. View Routine" << endl;
    cout << "2. Login as Employee" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "View Routine" << endl;
        viewRoutine();
        break;
    case 2:
        cout << "Login as Employee" << endl;
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    return 0;
}

void viewRoutine()
{
    string classStandardInput;
    cout << "Enter the class standard: " << endl;
    cin >> classStandardInput;
    string classStandard_fname = classStandardInput + ".txt";
    if (!classStandardChk(classStandard_fname))
    {
        cout << "Class Standard not found" << endl;
        return;
    }
    ifstream file(classStandard_fname, ios::out | ios::in);
    file.close();
}