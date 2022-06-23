#ifndef persistance_manager_h
#define persistance_manager_h

#include "user_attr.h"

class PersistanceManager_t
{
public:
    static bool save(const user_t &, std::string);
};

#endif