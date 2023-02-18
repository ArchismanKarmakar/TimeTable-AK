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