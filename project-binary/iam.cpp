#include "iam.h"
#include "persistance_manager.h"
#include "user_attr.h"
#include "obj_attr.h"
#include <iostream>
#include <fstream>

bool Authentication::doesUserExist(std::string username)
{
    std::string filePath = ObjectAttribute::getAbsolutePath(username);
    std::fstream fileStream;

    // Try opening the user's file; if it's new, the file stream object will return an error when attempting to open that file.
    fileStream.open(filePath);

    return fileStream.is_open();
}



bool Authentication::registerNewUser()
{
    std::string username, password, confirmPassword;

    std::cout << "Enter Username (case-insensitive)\n> ";
    std::cin >> username;

    // Check if the username is new; only then proceed
    if (doesUserExist(username))
    {
        std::cerr << "username : " << username << " is already taken. Try with a different ID.\n";
        return false;
    }

    // Validate new user input
    while (true)
    {
        std::cout << "Enter Password (alphanumeric ONLY)\n> ";
        std::cin >> password;
        std::cout << "Enter Confirm password\n> ";
        std::cin >> confirmPassword;

        if (password == confirmPassword)
        {
            break;
        }
    }

    // We have valid details, now persist the data
    if (PersistenceManager::saveUser(User(username, password), username))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Authentication::loginUser()
{
    std::string username, password;

    std::cout << "Enter Username (case-insensitive)\n> ";
    std::cin >> username;

    if (!doesUserExist(username))
    {
        std::cerr << "ID: " << username << " not found\n";
        return false;
    }
    else
    {
        // show his user name // TODO
        std::cout << "Hi " << username << ", please type your password!\n> ";
        std::cin >> password;

        std::fstream fileStream;
        fileStream.open(ObjectAttribute::getAbsolutePath(username));

        // Verify the password
        std::string passwordFromFile;
        fileStream >> passwordFromFile;

        if (passwordFromFile != password)
        {
            std::cout << "Unable to log in. Re-enter your password.\n> ";
            return false;
        }

        return true;
    }
}

bool Authentication::logoutUser()
{
    std::cerr << "Under maintenance\n";
    return false;
    // Implement the logout feature here when available.
    /*
    is logged in?

    */
}

void Authentication::userInterface()
{
    int working = 1, userChoice;

    while (working)
    {
        std::cout << "\n"
                  << "1 Register\n"
                  << "2 Login\n"
                  << "3 Logout\n"
                  << "0 QUIT\n> ";

        std::cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            if (registerNewUser())
                std::cout << "User registration successful!!\n";
            else
                std::cerr << "User registration failed!\n";
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