#include "obj_attr.h"

std::string ObjectAttribute::getAbsolutePath(std::string username)
{
    return "userDataStore/" + username;
}
