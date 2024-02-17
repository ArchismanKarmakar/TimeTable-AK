#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/employee.hh"
#include "./../include/table_manage.hh"

using namespace std;

Employee::Employee()
{
    id = -1;
    type = "";
    classesScheduled = 0;
    cat = "Employee";
    category = 1;
}
void Employee::fillMap()
{
    fstream f;
    f.open("./data/Employee.csv", ios::in);
    string temp;
    // skipping the first row containing column headers;
    getline(f >> ws, temp);
    // analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        Employee d;
        // creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s4, s5, s7, s9;
        // reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, d.firstName, ',');
        getline(s, d.lastName, ',');
        getline(s, s4, ',');
        getline(s, s5, ',');
        getline(s, d.mobNumber, ',');
        getline(s, s7, ',');
        getline(s, d.type, ',');
        getline(s, s9, ',');
        d.id = strToNum(s1);
        d.gender = s4[0];
        d.age = strToNum(s5);
        d.addr.strToAdd(s7);
        d.classesScheduled = strToNum(s9);
        table_manage::employeeList[d.id] = d;
    }
    f.close();
    return;
}
void Employee::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "doctorId,firstName,lastName,gender,age,mobNumber,address,type,classesScheduled\n";
    for (auto i : table_manage::employeeList)
        f << i.second.id << "," << i.second.firstName << "," << i.second.lastName << "," << i.second.gender
          << "," << i.second.age << "," << i.second.mobNumber << "," << i.second.addr.addToStr()
          << "," << i.second.type << "," << i.second.classesScheduled << endl;
    f.close();
    remove("./data/Employee.csv");
    rename("./data/temp.csv", "./data/Employee.csv");
    return;
}
void Employee::addPerson()
{
    if (table_manage::employeeList.size() == table_manage::employeeLimit)
    {
        cout << "\n\nDoctors limit reached, can't addr more!\n\n";
        return;
    }
    // 18 and 65 are the age limits for registration of a new Employee;
    Person::addPerson(18, 65);
    if ((age < 18) || (age > 65))
        return;
    cout << "\nEnter the type of the Employee: \n";
    getline(cin >> ws, type);
    if (table_manage::employeeList.rbegin() != table_manage::employeeList.rend())
        id = ((table_manage::employeeList.rbegin())->first) + 1;
    else
        id = 1;
    table_manage::employeeList[id] = *this;

    // creating a fstream object to read/write from/to files;
    fstream f;
    // creating a record in doctorsHistory.csv;
    f.open("./data/doctorsHistory.csv", ios::app);
    f << firstName << "," << lastName << "," << gender << "," << age << "," << mobNumber << "," << addr.addToStr() << "," << type << ",N,NA" << endl;
    f.close();

    cout << "\n"
         << firstName << " " << lastName << " registered successfully!\n";
    cout << "Their ID is: " << id << "\n";

    return;
}
void Employee::printDetails()
{
    if (id == -1)
        return;
    Person::printDetails();
    cout << "Type            : " << type << "\n";
    cout << "Appointments    : " << classesScheduled << "/8 (appointments booked today)\n";
    return;
}
void Employee::printDetailsFromHistory(string extraDetails)
{
    if (id == -1)
        return;
    Person::printDetailsFromHistory();
    stringstream k(extraDetails);
    string s1, s2;
    getline(k, s1, ',');
    getline(k, s2, ',');
    if (extraDetails == "")
    {
        fstream f;
        f.open("./data/doctorsHistory.csv", ios::in);
        string temp;
        // skipping the first row containing column headers;
        getline(f >> ws, temp);
        // analyzing each entry afterwards;
        while (getline(f >> ws, temp))
        {
            Employee d;
            // creating a string stream object to read from string 'temp';
            stringstream s(temp);
            string s4, s5, s7;
            // reading from the string stream object 's';
            getline(s, d.firstName, ',');
            getline(s, d.lastName, ',');
            getline(s, s4, ',');
            getline(s, s5, ',');
            getline(s, d.mobNumber, ',');

            if (d.firstName == firstName && d.lastName == lastName && d.mobNumber == mobNumber)
            {

                getline(s, s7, ',');
                getline(s, d.type, ',');
                getline(s, s1, ',');
                getline(s, s2, ',');
            }
        }
        f.close();
    }
    cout << "Type            : " << type << "\n";
    cout << "Left Work?      : " << s1 << "\n";
    if (s1 == "Y")
        cout << "Reason          : " << s2 << "\n";
    return;
}
void Employee::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n[3]: Filter by Type\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2 && opt != 3)
        cout << "option 1, 2 or 3?\n", cin >> opt;
    // 1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (table_manage::employeeList.find(reqId) != table_manage::employeeList.end())
            *this = table_manage::employeeList[reqId];
        else
            cout << "\nNo matching record found!\n";
    }
    // 2: Filter by name;
    else if (opt == 2)
    {
        string reqFName, reqLName;
        cout << "First Name:\n";
        getline(cin >> ws, reqFName);
        cout << "\nLast Name:\n";
        getline(cin, reqLName);
        vector<Employee> matchingRecords;
        for (auto i : table_manage::employeeList)
        {
            if (i.second.firstName == reqFName && i.second.lastName == reqLName)
                matchingRecords.push_back(i.second);
        }
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i : matchingRecords)
            i.printDetails();
        char tt = 'N';
        if (matchingRecords.size() > rec)
        {
            do
            {
                int reqId;
                cout << "\nEnter the ID of the required Employee: ";
                cin >> reqId;
                if (table_manage::employeeList.find(reqId) != table_manage::employeeList.end())
                    *this = table_manage::employeeList[reqId];
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
    // 3: Filter by type;
    else if (opt == 3)
    {
        string reqType;
        cout << "Enter the type of Employee required:\n";
        getline(cin >> ws, reqType);
        vector<Employee> matchingRecords;
        for (auto i : table_manage::employeeList)
        {
            if (i.second.type == reqType)
                matchingRecords.push_back(i.second);
        }
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i : matchingRecords)
            i.printDetails();
        char tt = 'N';
        if (matchingRecords.size() > 0)
            do
            {
                int reqId;
                cout << "\nEnter the ID of the required Employee: ";
                cin >> reqId;
                if (table_manage::employeeList.find(reqId) != table_manage::employeeList.end())
                    *this = table_manage::employeeList[reqId];
                else
                {
                    cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    cin >> tt;
                    while (tt != 'Y' || tt != 'N')
                        cout << "Y or N?\n", cin >> tt;
                }
            } while (tt == 'Y');
    }
    return;
}
void Employee::getDetailsFromHistory()
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by Name\n[2]: Filter by Type\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2)
        cout << "option 1 or 2?\n", cin >> opt;

    // 1: Filter by name;
    if (opt == 1)
    {
        string reqFName, reqLName;
        cout << "First Name:\n";
        getline(cin >> ws, reqFName);
        cout << "\nLast Name:\n";
        getline(cin, reqLName);
        vector<Employee> matchingRecords;
        vector<string> extraDetails;
        fstream f;
        f.open("./data/doctorsHistory.csv", ios::in);
        string temp;
        // skipping the first row containing column headers;
        getline(f >> ws, temp);
        // analyzing each entry afterwards;
        while (getline(f >> ws, temp))
        {
            Employee d;
            // creating a string stream object to read from string 'temp';
            stringstream s(temp);
            string s4, s5, s7, s9;
            // reading from the string stream object 's';
            getline(s, d.firstName, ',');
            getline(s, d.lastName, ',');

            if (d.firstName == reqFName && d.lastName == reqLName)
            {
                getline(s, s4, ',');
                getline(s, s5, ',');
                getline(s, d.mobNumber, ',');
                getline(s, s7, ',');
                getline(s, d.type, ',');
                getline(s, s9);
                d.id = 0;
                d.gender = s4[0];
                d.age = strToNum(s5);
                d.addr.strToAdd(s7);
                matchingRecords.push_back(d);
                extraDetails.push_back(s9);
            }
        }
        f.close();
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (int i = 0; i < matchingRecords.size(); i++)
            matchingRecords[i].printDetailsFromHistory(extraDetails[i]);
    }
    // 2: Filter by type;
    else if (opt == 2)
    {
        string reqType;
        cout << "Enter the type of Employee required:\n";
        getline(cin >> ws, reqType);
        vector<Employee> matchingRecords;
        vector<string> extraDetails;
        fstream f;
        f.open("./data/doctorsHistory.csv", ios::in);
        string temp;
        // skipping the first row containing column headers;
        getline(f >> ws, temp);
        // analyzing each entry afterwards;
        while (getline(f >> ws, temp))
        {
            Employee d;
            // creating a string stream object to read from string 'temp';
            stringstream s(temp);
            string s4, s5, s7, s9;
            // reading from the string stream object 's';
            getline(s, d.firstName, ',');
            getline(s, d.lastName, ',');
            getline(s, s4, ',');
            getline(s, s5, ',');
            getline(s, d.mobNumber, ',');
            getline(s, s7, ',');
            getline(s, d.type, ',');
            if (d.type == reqType)
            {
                getline(s, s9);
                d.id = 0;
                d.gender = s4[0];
                d.age = strToNum(s5);
                d.addr.strToAdd(s7);
                matchingRecords.push_back(d);
                extraDetails.push_back(s9);
            }
        }
        f.close();
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (int i = 0; i < matchingRecords.size(); i++)
            matchingRecords[i].printDetailsFromHistory(extraDetails[i]);
    }
    return;
}
void Employee::removePerson()
{
    cout << "\nSearch for the Employee you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (classesScheduled > 0)
    {
        cout << "\nSelected Employee has appointments booked for today, can't be removed.\n\n";
        return;
    }
    table_manage::employeeList.erase(id);

    string s, temp;
    stringstream str;
    fstream f, fout;
    string reason;
    cout << "\nReason?\n";
    getline(cin >> ws, reason);
    str << firstName << "," << lastName << "," << gender << "," << age
        << "," << mobNumber << "," << addr.addToStr() << "," << type << ",N,NA\n";
    getline(str, s);
    f.open("./data/doctorsHistory.csv", ios::in);
    fout.open("./data/temp.csv", ios::out);
    while (getline(f, temp))
    {
        if (temp == s)
        {
            fout << firstName << "," << lastName << "," << gender << "," << age
                 << "," << mobNumber << "," << addr.addToStr() << "," << type << ",Y," << reason << "\n";
        }
        else
            fout << temp << "\n";
    }
    f.close();
    fout.close();
    s.erase();
    temp.erase();
    remove("./data/doctorsHistory.csv");
    rename("./data/temp.csv", "./data/doctorsHistory.csv");
    cout << firstName << " " << lastName << " removed successfully!\n";
    return;
}