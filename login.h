class DecryptPass
{
public:
    bool securityChk();
    DecryptPass(char *uname)
    {
        username = uname;
    }

private:
    std::string username;
};