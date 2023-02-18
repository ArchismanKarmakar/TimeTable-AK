class EncryptPass
{
public:
    bool createUser();
    EncryptPass(char *uname)
    {
        username = uname;
    }

private:
    string username;
};