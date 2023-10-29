#ifndef IAM_H
#define IAM_H

#include <string>

class Authentication
{
public:
    void userInterface();

private:
    bool doesUserExist(std::string username);
    bool registerNewUser();
    bool loginUser();
    bool logoutUser();

    // Add any private members or methods specific to Authentication here.
};

#endif
