#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                         \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

class TimeTable
{
public:
    int getDay();
    void setDay(int day);
    void displayRoutine(std::string uname);

private:
    int day = 0;
};

class Period : public TimeTable
{
public:
    void periodConstructor(int periodNo, int startTime, int endTime, std::string facultyId, std::string subId, int day, int totalPeriods)
    {
        this->periodNo = periodNo;
        this->startTime = startTime;
        this->endTime = endTime;
        this->facultyId = facultyId;
        this->subId = subId;
    }
    void openFileChk(std::string uname);

private:
    int periodNo;
    int startTime;
    int endTime;
    std::string facultyId;
    std::string subId;
};