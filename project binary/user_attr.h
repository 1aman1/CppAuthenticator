#ifndef user_attr_h
#define user_attr_h

#include <string>

class user_t
{
public:
    std::string username;
    std::string password;

    user_t(std::string, std::string);

    std::string getUserName();
    std::string getPassword();
};

#endif
