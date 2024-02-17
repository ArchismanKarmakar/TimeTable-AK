using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/routine.hh"
#include "./../include/employee.hh"
#include "./../include/table_manage.hh"

Routine::Routine()
{
    id = -1;
    D.id = -1;
    P.courseId = -1;
}
Routine::~Routine()
{
    id = -1;
    D.id = -1;
    P.courseId = -1;
    return;
}
void Routine::fillMap()
{
    fstream f;
    f.open("./data/appointments.csv", ios::in);
    string temp;
    // skipping the first row containing column headers;
    getline(f >> ws, temp);
    // analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        Routine a;
        // creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s2, s3, s4, s5;
        // reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s2, ','); // date is of no use here;
        getline(s, s3, ',');
        getline(s, s4, ',');
        getline(s, s5, ',');
        a.id = strToNum(s1);
        a.D = table_manage::employeeList[strToNum(s3)];
        a.P = table_manage::courseList[strToNum(s4)];
        a.hh = strToNum(s5);
        table_manage::appointmentsList[a.id] = a;
    }
    f.close();
    return;
}
void Routine::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "appointmentId,date(YYYYMMDD),doctorId,patientId,startTime(in 24-hr format)\n";
    for (auto i : table_manage::appointmentsList)
        f << i.second.id << "," << yyyymmdd << "," << i.second.D.id << "," << i.second.P.courseId
          << "," << i.second.hh << endl;
    f.close();
    remove("./data/appointments.csv");
    rename("./data/temp.csv", "./data/courses.csv");
    return;
}
void Routine::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\n\nAppointment Details:\nID                 : " << id << "\n"
         << "Course Name     : " + P.courseName + " " + P.courseDetails + "(ID = " << P.courseId << ")\n"
         << "Employee's Name      : " + D.firstName + " " + D.lastName + "(ID = " << D.id << ")\n"
         << "Time (24 Hr format): " << hh << ":00 Hrs to " << hh + 1 << ":00 Hrs\n\n";
    return;
}
void Routine::book()
{
    if (table_manage::appointmentsList.size() >= 8 * table_manage::employeeList.size())
    {
        cout << "\n\nSorry, no doctor is available for Routine today!\n\n";
        return;
    }
    cout << "\n\nIs the patient already registered (Y : Yes || N : No)?\n";
    char ans;
    cin >> ans;
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Y or N?\n";
        cin >> ans;
    }
    if (ans == 'N')
    {
        cout << "Register the patient:\n";
        P.addCourse();
    }
    else
    {
        cout << "Search for the required course:\n\n";
        ans = 'Y';
        while (ans == 'Y')
        {
            P.getDetails();
            ans = 'K';
            if (P.courseId == -1)
            {
                cout << "Try again (Y : Yes || N : No)?\n";
                cin >> ans;
                while (ans != 'Y' && ans != 'N')
                {
                    cout << "Y or N?\n";
                    cin >> ans;
                }
            }
        }
        if (ans == 'N')
        {
            return;
        }
    }
    cout << "\n\nNow, search for the required doctor:\n";
    ans = 'Y';
    while (ans == 'Y')
    {
        D.getDetails();
        ans = 'K';
        if (D.id == -1)
        {
            cout << "Try again (Y : Yes || N : No)?\n";
            cin >> ans;
            while (ans != 'Y' && ans != 'N')
            {
                cout << "Y or N?\n";
                cin >> ans;
            }
        }
        else if (D.appointmentsBooked >= 8)
        {
            cout << "Sorry, selected doctor has no free slot left for the day!\n";
            cout << "Search again (Y : Yes || N : No)?\n";
            cin >> ans;
            while (ans != 'Y' && ans != 'N')
            {
                cout << "Y or N?\n";
                cin >> ans;
            }
        }
    }
    if (ans == 'N')
    {
        return;
    }
    if (table_manage::appointmentsList.rbegin() != table_manage::appointmentsList.rend())
        id = ((table_manage::appointmentsList.rbegin())->first) + 1;
    else
        id = 1;
    hh = 9 + D.appointmentsBooked;
    table_manage::appointmentsList[id] = *this;

    table_manage::doctorsList[D.id].appointmentsBooked++;
    cout << "\nAppointment of patient " + P.firstName + " " + P.lastName + " with doctor "
         << D.firstName << " " << D.lastName << " booked successfully!\n";
    printDetails();
    return;
}
void Routine::getDetails()
{
    cout << "\nEnter Routine ID:\n";
    cin >> id;
    if (table_manage::appointmentsList.find(id) == table_manage::appointmentsList.end())
    {
        cout << "\nInvalid Routine ID!\n";
        id = -1;
        return;
    }
    *this = table_manage::appointmentsList[id];
    return;
}