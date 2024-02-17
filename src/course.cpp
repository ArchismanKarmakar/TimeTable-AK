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

#include "./../include/course.hh"
#include "./../include/table_manage.hh"

using namespace std;

// Course::Course(string courseId, string coursedetails)
// {
//     this->courseId = courseId;
//     this->courseDetails = coursedetails;
// }

void Course::print()
{
    cout << "Course ID: " << courseId << "\n";
    cout << "Course Details: " << courseDetails << "\n";
    return;
}

void Course::takeInput()
{
    cout << "Enter Course ID: ";
    // getline(cin >> ws, courseId);
    cin >> courseId;
    cout << "Enter Course Details: ";
    getline(cin >> ws, courseDetails);
    return;
}

string Course::addToStr(string str)
{
    stringstream s;
    s << courseId << "`" << courseDetails;
    string addable;
    getline(s, addable);
    for (auto &i : addable)
        if (i == ',')
            i = '^';
    return addable;
}

void Course::strToAdd(string str)
{
    stringstream s(str);
    // getline(s, courseId, '`');
    // // getline(s, courseDetails);
    // for (auto &i : courseId)
    //     if (i == '^')
    //         i = ',';
    // return;
    cin >> courseId;
    getline(s, courseDetails, '`');
}

void Course::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "courseId,courseName,courseDetails\n";
    for (auto i : table_manage::courseList)
        f << i.second.courseId << "," << i.second.courseName << "," << i.second.courseDetails << endl;
    f.close();
    remove("./data/courses.csv");
    rename("./data/temp.csv", "./data/courses.csv");
    return;
}

void Course::addCourse()
{
    cout << "\nEnter the course name:\n";
    getline(cin >> ws, courseName);
    cout << "\nEnter the course details:\n";
    getline(cin >> ws, courseDetails);
    fstream f;
    f.open("./data/coursesHistory.csv", ios::app);
    f << courseId << "," << courseName << "," << courseDetails << "\n";
    f.close();

    cout << "\n"
         << courseId << " " << courseName << " has been successfully!\n";
    cout << "Their ID is: " << courseId << "\n";

    return;
}

void Course::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2)
        cout << "option 1 or 2?\n", cin >> opt;
    // 1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (table_manage::courseList.find(reqId) != table_manage::courseList.end())
            *this = table_manage::courseList[reqId];
        else
            cout << "\nNo matching record found!\n";
    }
    // 2: Filter by name;
    else if (opt == 2)
    {
        string reqFName, reqLName;
        cout << "Name:\n";
        getline(cin >> ws, reqFName);
        vector<Course> matchingRecords;
        for (auto i : table_manage::courseList)
        {
            if (i.second.courseName == reqFName)
                matchingRecords.push_back(i.second);
        }
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i : matchingRecords)
            i.print();
        char tt = 'N';
        if (matchingRecords.size() > rec)
        {
            do
            {
                int reqId;
                cout << "\nEnter the ID of the required course: ";
                cin >> reqId;
                if (table_manage::courseList.find(reqId) != table_manage::courseList.end())
                    *this = table_manage::courseList[reqId];
                else
                {
                    cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    cin >> tt;
                    while (tt != 'Y' || tt != 'N')
                        cout << "Y or N?\n", cin >> tt;
                }
            } while (tt == 'Y');
        }
    }
    return;
}

void Course::removeCourse()
{
    cout << "\nSearch for the patient you want to discharge.\n";
    getDetails();
    if (courseId == -1)
        return;
    // if (!hospitalized)
    // {
    //     cout << "\nPatient wasn't hospitalized, can't be discharged!\n\n";
    //     return;
    // }
    // hospital::patientsList.erase(id);
    string s, temp;
    stringstream str;
    fstream f, fout;
    str << courseId << courseName << "," << courseDetails << "\n";
    getline(str, s);
    f.open("./data/coursesHistory.csv", ios::in);
    fout.open("./data/temp.csv", ios::out);
    while (getline(f, temp))
    {
        if (temp == s)
        {
            fout << courseId << courseName << "," << courseDetails << "\n";
        }
        else
            fout << temp << "\n";
    }
    f.close();
    fout.close();
    s.erase();
    temp.erase();
    remove("./data/coursesHistory.csv");
    rename("./data/temp.csv", "./data/coursesHistory.csv");
    cout << courseId << " " << courseName << " " << courseDetails << " deleted!\n";
    return;
}
