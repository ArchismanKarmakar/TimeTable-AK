class DecryptPass
{
public:
    bool securityChk();
    DecryptPass(char *uname)
    {
        username = uname;
    }

private:
    string username;
};