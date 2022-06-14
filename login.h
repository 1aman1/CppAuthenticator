#ifndef login_h
#define login_h

// header guard above

class userRegistration_t
{
private:
    bool writeToDisk(user_t newUser);

public:
    void interface();
    bool registerNewUserAccount();
    bool login();
    bool logout();
};

#endif
