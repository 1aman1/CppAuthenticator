#ifndef user_h
#define user_h

#include <string>

class user_t
{
public:
    user_t(std::string, std::string);

    std::string username;
    std::string password;
};

#endif
