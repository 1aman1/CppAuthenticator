#include "iam.h"
#include "persistance_manager.h"
#include "user_attr.h"
#include "obj_attr.h"

#include <iostream>
#include <fstream>

/*

*/

bool auth_t::ifUserExists(std::string username)
{
    // get absolute path

    std::string file = objAttribute_t::getAbsFile(username);
    std::fstream ifso;

    // try opening the same user,
    // if it is new, file stream obj will return error in attempt to open that file
    ifso.open(file);

    if (ifso.is_open())
        return true;
    else
        return false;
}

bool auth_t::registerNew()
{
    std::string username, password, confirmpassword;
    bool matchPass = true;

    std::cout << "username(case-insensitive)\n";
    std::cin >> username;

    /*
    we check if the username is new, only then we proceed
    */

    if (ifUserExists(username))
    {
        std::cerr << " ID: " << username << " already present!! \n Try with a different ID";
        return false;
    }

    // - MILESTONE : VALID NEW USER ^

    while (matchPass)
    {
        std::cout << "password(alphanumeric ONLY)\n";
        std::cin >> password;
        std::cout << "confirm password\n";
        std::cin >> confirmpassword;

        if (password == confirmpassword)
        {
            std::cout << "re-enter password\n";
            matchPass = false;
        }
    }

    // - MILESTONE : VALID INPUT ^

    // we have details, now persist data
    if (PersistanceManager_t::save(user_t(username, password), username))
        return true;
    else
        return false;
}

bool auth_t::loginUser()
{
    std::string username;
    std::string password;

    std::cout << "your username ? : ";
    std::cin >> username;

    if (!ifUserExists(username))
    {
        std::cerr << " ID: " << username << "not found";
        return false;
    }

    else
    {
        std::cout << "We found your profile, input your password !!\n";
        std::cin >> password;

        std::fstream ifso;

        ifso.open(objAttribute_t::getAbsFile(username));

        // verify password
        std::string textFromFile;
        ifso >> textFromFile;

        if (textFromFile != password)
        {
            std::cout << "Unable to loginUser, check password\n";
            return false;
        }

        std::cout << "Logged in\n";
        return true;
    }
}

bool auth_t::logoutUser()
{
    std::cerr << "under maintenance\n";
    return false;
}

void auth_t::interface()
{
    int working = 1, userChoice;

    while (working)
    {
        std::cout << "\n"
                  << "  1 Register\n"
                  << "  2 Login\n"
                  << "  3 Logout\n"
                  << "  0 QUIT\n";

        std::cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            if (registerNew())
                std::cout << "user registered!!\n";
            else
                std::cerr << "user registration failed!\n";
        }
        break;

        case 2:
        {
            if (loginUser())
                std::cout << "Login successful !!\n";
            else
                std::cerr << "Login failed !!\n";
        }
        break;

        case 3:
        {
            if (logoutUser())
                std::cout << "Logged Out\n";
            else
                std::cerr << "Logout failed!\n";
        }
        break;

        case 0:
        {
            working = false;
        }
        break;

        default:
        {
            std::cout << "Going back to interface\n";
        }
        break;
        }
    }
}