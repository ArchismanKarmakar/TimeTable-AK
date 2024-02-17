#ifndef TABLE_MANAGE
#define TABLE_MANAGE

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

#include "./employee.hh"
// #include "./patient.hh"
// #include "./nurse.hh"
// #include "./driver.hh"
// #include "./ambulance.hh"
// #include "./appointment.hh"

#define ull unsigned long long

using namespace std;

class classStandard
{
public:
    void classStandardCreate(std::string classStandard_fname);

    void periodConstructor(ull periodNo)
    {
    }

    void displayRoutine();

    classStandard(string classStandard_fname);

private:
    ull periodNo;
};

bool classStandardChk(std::string classStandard_fname);

class table_manage
{
private:
    //map<id, object>
    static map<int, Employee> employeeList;
    // static map<int, patient> patientsList;
    // static map<int, nurse> nursesList;
    // static map<int, driver> driversList;
    // static map<int, ambulance> ambulancesList;
    // static map<int, appointment> appointmentsList;

    static const int employeeLimit;
    // static const int nursesLimit;
    // static const int driversLimit;
    // static const int ambulancesLimit;
    // static const int appointmentsLimit;

    friend class Employee;
    // friend class patient;
    // friend class nurse;
    // friend class driver;
    // friend class ambulance;
    // friend class appointment;

public:
    static void printEmployees();
    // static void printPatients();
    // static void printNurses();
    // static void printDrivers();
    // static void printAmbulances();
    // static void printAppointments();
};

#endif