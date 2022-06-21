#ifndef persistance_manager_h
#define persistance_manager_h

#include <iostream>
class user_t
{
public:
    std::string username;
    std::string password;

    user_t(std::string un, std::string pwd);

    std::string getUserName();
    std::string getPassword();
};

class PersistanceManager_t
{
public:
    static bool save(const user_t &userObj, std::string filename);
};

#endif