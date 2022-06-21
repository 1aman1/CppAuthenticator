#include <string>

class user_t
{
public:
    std::string username;
    std::string password;

    user_t(std::string un, std::string pwd);

    std::string getUserName();
    std::string getPassword();
};

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
