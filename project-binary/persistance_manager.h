#ifndef PERSISTANCE_MANAGER_H
#define PERSISTANCE_MANAGER_H

#include "user_attr.h"
#include "obj_attr.h"
#include <fstream>

class PersistenceManager
{
public:
    static bool saveUser(const User &userObj, std::string username);
};

#endif
