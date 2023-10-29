#include "user_attr.h"

User::User(std::string un, std::string pwd) : username(un), password(pwd)
{
}

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}
