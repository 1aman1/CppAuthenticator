#ifndef USER_ATTR_H
#define USER_ATTR_H

#include <string>

class User
{
public:
    User(std::string un, std::string pwd);
    std::string getUsername() const;
    std::string getPassword() const;

private:
    std::string username;
    std::string password;
};

#endif
