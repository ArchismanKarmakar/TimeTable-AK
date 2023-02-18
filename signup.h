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