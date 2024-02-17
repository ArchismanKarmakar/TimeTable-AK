#ifndef COURSE
#define COURSE

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

using namespace std;

class Course
{
public:
    // Course(string course, string details);

    void print();
    void addCourse();
    void takeInput();
    void strToAdd(string str);
    string addToStr(string str);
    void getDetails(int rec=0);
    void saveMap();
    void getDetailsFromHistory();
    void removeCourse();

protected:
    int courseId;
    string courseName;
    string courseDetails;

private:
    friend class Routine;
};

#endif