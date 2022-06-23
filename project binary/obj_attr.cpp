#include "obj_attr.h"

std::string objAttribute_t::location = "userDataStore/";
std::string objAttribute_t::ufoExtension = ".ufo";

std::string objAttribute_t::getFile(std::string username)
{
    return (username + ufoExtension);
}

std::string objAttribute_t::getAbsFile(std::string username)
{
    return (location + username + ufoExtension);
}