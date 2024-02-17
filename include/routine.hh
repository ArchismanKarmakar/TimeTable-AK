#ifndef ROUTINE
#define ROUTINE
using namespace std;

#include "./course.hh"
#include "./employee.hh"
// #include "./person.hh"

class Routine
{
private:
    int id;
    Employee D;
    Course P;
    int hh; // hh -> start hour in 24 hour format;

public:
    Routine();
    ~Routine();
    void fillMap();
    void saveMap();
    void printDetails();
    void book();
    void fillDetails();
    void getDetails();
};
#endif // !ROUTINE