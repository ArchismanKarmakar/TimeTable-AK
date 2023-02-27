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

#include <./../include/faculty.hh>
#include <./../include/global.hh>

using namespace std;

Faculty::Faculty()
{
    id = -1;
}

void Faculty::addFaculty(int16_t minAge, int16_t maxAge)
{
    cout << "\nEnter Id: \n";
    getline(cin >> ws, id);
    if (std::filesystem::exists("./data/" + id + ".csv"))
        return void(cout << "Sorry, this Faculty ID is already registered.\n");
    cout << "\nEnter name: ";
    getline(cin >> ws, name);

    cout << "\nEnter age: \n";
    cin >> age;
    while (age <= 0)
    {
        cout << "Was that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
        if (age < minAge)
            return void(cout << "Sorry, person should be at least " << minAge << " years old to be registered.\n");
        else if (age > maxAge)
            return void(cout << "Sorry, we can't register a person older than " << maxAge << " years.\n");
    }

    cout << "\nEnter mobile number (with country code): \n";
    getline(cin >> ws, phone);
    cout << "\nGender (M = Male || F = Female): \n";
    cout << "\nEnter email: \n";
    getline(cin >> ws, email);
    cin >> gender;
    while (gender != 'M' && gender != 'F')
        cout << "M or F?\n", cin >> gender;

    fstream f;
    string path = "./data/" + id + ".csv";
    f.open(path, ios::in);
    // `le first line conataining column headers:
    // f << "Id,Name,age,phone,email,gender\n";
    // for (auto i : Faculty::appointmentsList)
    f << id << name << "," << age << "," << phone << "," << email
      << "," << gender << endl;
    f.close();
    // add.takeInput();
    return;
}

void Faculty::fillMap()
{
    string id;
    cout << "\nEnter Id to fill: \n";
    cin >> id;
    if (!std::filesystem::exists("./data/" + id + ".csv"))
        return void(cout << "Sorry, this Faculty ID is not registered.\n");
    fstream f;
    string path = "./data/" + id + ".csv";
    f.open(path, ios::in);
    string temp;
    // //skipping the first row containing column headers;
    // getline(f >> ws, temp);
    // analyzing each entry afterwards;
    // (getline(f >> ws, temp));
    {
        Faculty a;
        // creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s5, s6, s7;
        // reading from the string stream object 's';
        getline(s, a.id, ',');
        getline(s, a.name, ',');
        getline(s, s1, ',');
        getline(s, a.phone, ',');
        getline(s, a.email, ',');
        // getline(s, a.gender, ',');
        getline(s, s7, ',');
        a.age = strToNum(s1);
        a.gender = s7[0];
        // if (!a.idle)
        // {
        //     a.add.strToAdd(s6);
        //     a.D = Faculty::driversList[strToNum(s7)];
        // }
        // Faculty::FacultyList[a.id] = a;
    }
    f.close();
    return;
}

void Faculty::editMap()
{
    string id;
    cout << "\nEnter Id to edit: \n";
    cin >> id;
    if (!std::filesystem::exists("./data/" + id + ".csv"))
        return void(cout << "Sorry, this Faculty ID is not registered.\n");

    fstream f;
    string path = "./data/" + id + ".csv";
    f.open(path, ios::in);
    string temp;
    // //skipping the first row containing column headers;
    // getline(f >> ws, temp);
    // analyzing each entry afterwards;
    // (getline(f >> ws, temp));
    {
        // Faculty a;
        // creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s5, s6, s7;
        // reading from the string stream object 's';
        getline(s, id, ',');
        getline(s, name, ',');
        getline(s, s1, ',');
        getline(s, phone, ',');
        getline(s, email, ',');
        // getline(s, a.gender, ',');
        getline(s, s7, ',');
        age = strToNum(s1);
        gender = s7[0];
    }
    f.close();

    int choice = 0;

    while (choice != 5)
    {
        cout << "\nWhat do you want to edit?\n";
        cout << "1. Name\n";
        cout << "2. Age\n";
        cout << "3. Phone\n";
        cout << "4. Email\n";
        cout << "5. Gender\n";
        cout << "6. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nEnter name: ";
            getline(cin >> ws, name);
            break;
        }
        case 2:
        {
            cout << "\nEnter age: \n";
            cin >> age;
            while (age <= 0)
            {
                cout << "Was that supposed to make any kind of sense?\nEnter again!\n", cin >> age;
                if (age < 18)
                    return void(cout << "Sorry, person should be at least 18 years old to be registered.\n");
                else if (age > 100)
                    return void(cout << "Sorry, we can't register a person older than 100 years.\n");
            }
            break;
        }
        case 3:
        {
            cout << "\nEnter mobile number (with country code): \n";
            getline(cin >> ws, phone);
            break;
        }
        case 4:
        {
            cout << "\nEnter email: \n";
            getline(cin >> ws, email);
            break;
        }
        case 5:
        {
            choice = 5;
            break;
        }
        default:
        {
            return void(cout << "Invalid choice!\n");
            break;
        }
        }
    }
    remove((char *)path.c_str());
    fstream f;
    string path = "./data/" + id + ".csv";
    f.open(path, ios::out);

    f << id << name << "," << age << "," << phone << "," << email
      << "," << gender << endl;
    f.close();

    // `le first line conataining column headers:
    // f << "Id,Name,age,phone,email,gender\n";
    // for (auto i : Faculty::appointmentsList)
    // f << id << "," << yyyymmdd << "," << i.second.D.id << "," << i.second.P.id
    //   << "," << i.second.hh << endl;
    // f.close();
    // rename("./data/temp.csv", "./data/appointments.csv");
    return;
}

void Faculty::removeFaculty()
{
    string id;
    cout << "\nEnter Id to edit: \n";
    cin >> id;
    if (!std::filesystem::exists("./data/" + id + ".csv"))
        return void(cout << "Sorry, this Faculty ID is not registered.\n");

    remove((char *)("./data/" + id + ".csv").c_str());
    return void(cout << "Faculty removed successfully!\n");
}