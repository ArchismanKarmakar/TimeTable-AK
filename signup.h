class EncryptPass
{
public:
    bool createUser();
    EncryptPass(string uname)
    {
        username = uname;
    }

private:
    string username;
};