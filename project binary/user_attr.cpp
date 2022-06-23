#include "user_attr.h"

/*

*/

user_t::user_t(std::string un, std::string pwd)
{
    this->username = un;
    this->password = pwd;
}

std::string user_t::getUserName()
{
    return username;
}

std::string user_t::getPassword()
{
    return password;
}
