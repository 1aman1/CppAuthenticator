#include "persistance_manager.h"
#include "iam.h"
#include "user_attr.h"
#include "obj_attr.h"

#include <iostream>
#include <fstream>

/*

*/
bool PersistanceManager_t::save(const user_t &userObj, std::string username)
{
    std::ofstream ofs;

    // get absolute object path
    std::string fileObj = objAttribute_t::getAbsFile(username);

    ofs.open(fileObj);

    if (!ofs.is_open())
    {
        std::cout << "could not open file for writing\n";
    }
    else
    {
        ofs << userObj.password << std::endl;
        ofs.close();
    }

    // verify if (fileObj) is present
    std::ifstream ifs(fileObj);
    if (!ifs)
    {
        std::cerr << "could not verify created user obj file\n";
        return false;
    }

    return true;
}