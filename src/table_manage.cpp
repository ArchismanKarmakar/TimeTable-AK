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

#include "./../include/table_manage.hh"
#include "./../include/employee.hh"
// #include "./../include/patient.hh"
// #include "./../include/nurse.hh"
// #include "./../include/driver.hh"
// #include "./../include/ambulance.hh"
// #include "./../include/appointment.hh"
// #include "./../include/table_manage.hh"

using namespace std;

bool classStandardChk(string classStandard_fname)
{
    string fname = classStandard_fname + ".txt";
    if (!std::filesystem::exists(fname))
    {
        return false;
    }
    ifstream file(fname, ios::out | ios::in);
    file.close();
}


//defining already declared static members in the global scope;

map<int, Employee> table_manage::employeeList;
// map<int, patient> table_manage::patientsList;
// map<int, nurse> table_manage::nursesList;
// map<int, driver> table_manage::driversList;
// map<int, ambulance> table_manage::ambulancesList;
// map<int, appointment> table_manage::appointmentsList;

const int table_manage::employeeLimit = 30;
// const int table_manage::nursesLimit = 50;
// const int table_manage::driversLimit = 30;
// const int table_manage::ambulancesLimit = 30;
// const int table_manage::appointmentsLimit = 240; //per day;
// ummm, patients limit, ummm, no!
// appointments limit is kind of a patients limit;
// rest hospitalized patients limit must be equal to;
// number of available rooms, maybe I'll add this;
// feature some other day in the future;
// not feeling like doing it right now!

//defining already declared methods;

void table_manage::printEmployees()
{
    for (auto i : employeeList)
        i.second.printDetails(), cout << "\n";
    return;
}
// void table_manage::printPatients()
// {
//     for (auto i : patientsList)
//         i.second.printDetails(), cout << "\n";
//     return;
// }
// void table_manage::printNurses()
// {
//     for (auto i : nursesList)
//         i.second.printDetails(), cout << "\n";
//     return;
// }
// void table_manage::printDrivers()
// {
//     for (auto i : driversList)
//         i.second.printDetails(), cout << "\n";
//     return;
// }
// void table_manage::printAmbulances()
// {
//     for (auto i : ambulancesList)
//         i.second.printDetails(), cout << "\n";
//     return;
// }
// void table_manage::printAppointments()
// {
//     for (auto i : appointmentsList)
//         i.second.printDetails(), cout << "\n";
//     return;
// }