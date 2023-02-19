#define pause()                               \
    do                                        \
    {                                         \
        cout << "\n";                          \
    } while (cin.get() != '\n');              \
    do                                        \
    {                                         \
        cout << "Press a key to continue..."; \
    } while (cin.get() != '\n')

class EncryptPass
{
public:
    bool createUser();
    EncryptPass(std::string uname)
    {
        username = uname;
    }

private:
    std::string username;
};