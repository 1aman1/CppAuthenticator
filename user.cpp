#include <string>

class user_t
{
private:
    std::string username;
    std::string password;

public:
    user_t(std::string un, std::string pwd);
    std::string getUserName();
    // reset userName
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
