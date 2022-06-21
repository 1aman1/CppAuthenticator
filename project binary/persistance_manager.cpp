#include <iostream>
#include <fstream>

class user_t
{
public:
    std::string username;
    std::string password;

    user_t(std::string, std::string);

    std::string getUserName();
    std::string getPassword();
};

/*
forward declaration above
*/

class PersistanceManager_t
{
public:
    static bool save(const user_t &userObj, std::string filename);
};

bool PersistanceManager_t::save(const user_t &userObj, std::string filename = "filename.txt")
{
    std::ofstream ofs;

    // add folder path
    filename = "userDataStore/" + filename;

    ofs.open(filename);
    if (ofs.is_open())
    {
        ofs << userObj.username << std::endl;
        ofs << userObj.password << std::endl;

        // std::cout << "file saved \n";
        ofs.close();
    }
    else
    {
        std::cout << "could not open file for writing\n";
    }

    // check if (filename) is present, then successful
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "could not verify created user obj file\n";
        return false;
    }

    return true;
}