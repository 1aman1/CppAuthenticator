#include "persistance_manager.h"
#include <iostream>

bool PersistenceManager::saveUser(const User &userObj, std::string username)
{
    std::ofstream fileStream;

    // Get the absolute file path
    std::string filePath = ObjectAttribute::getAbsolutePath(username);

    fileStream.open(filePath);

    if (!fileStream.is_open())
    {
        std::cerr << "Could not open the file for writing\n";
        return false;
    }

    fileStream << userObj.getPassword() << std::endl;
    fileStream.close();

    // Verify if the file exists
    std::ifstream fileCheck(filePath);
    if (!fileCheck)
    {
        std::cerr << "Could not verify the created user object file\n";
        return false;
    }

    return true;
}
