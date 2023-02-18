#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                          \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

class DecryptPass
{
public:
    bool securityChk();
    DecryptPass(std::string uname)
    {
        username = uname;
    }

private:
    std::string username;
};