class DecryptPass
{
public:
    bool securityChk();
    DecryptPass(string uname)
    {
        username = uname;
    }

private:
    string username;
};