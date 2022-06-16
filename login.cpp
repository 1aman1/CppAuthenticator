#include <iostream>
#include <fstream>

class user_t
{
public:
    user_t(std::string, std::string);
    std::string getUserName();
};
/*
    forward declaration above
*/

class userRegistration_t
{
private:
    bool writeToDisk(user_t newUser);

public:
    void interface();
    bool registerNewUserAccount();
    bool login();
    bool logout();
};

void userRegistration_t::interface()
{
    int working = 1, userChoice;

    while (working)
    {
        std::cout << "\n 0 Register\n"
                  << "  1 Login\n"
                  << "  2 Logout\n";

        std::cin >> userChoice;

        switch (userChoice)
        {
        case 0:
        {
            if (registerNewUserAccount())
                std::cout << "created!!\n";
            else
                std::cerr << "failed!\n";
        }
        break;

        case 1:
        {
            if (login())
                std::cout << "Logged In\n";
            else
                std::cerr << "Login failed!\n";
        }
        break;

        case 2:
        {
            if (logout())
                std::cout << "Logged Out\n";
            else
                std::cerr << "Logout failed!\n";
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

bool userRegistration_t::registerNewUserAccount()
{
    std::string userName;
    std::cout << "username(case-insensitive)\n";
    std::cin >> userName;

    bool passCheck = true;
    std::string password, confirmpassword;

    while (passCheck)
    {
        std::cout << "password(alphanumeric ONLY)\n";
        std::cin >> password;
        std::cout << "confirm password\n";
        std::cin >> confirmpassword;

        if (password == confirmpassword)
        {
            std::cout << "re-enter password\n";
            passCheck = false;
        }
    }

    // we have details, now data persistence procedure
    if (writeToDisk(user_t(userName, password)))
        std::cout << "saved !\n";
    else
        std::cout << "could not save !\n";
}

bool userRegistration_t::login()
{
}

bool userRegistration_t::logout()
{
}

bool userRegistration_t::writeToDisk(user_t newUser)
{
    // std::ofstream file_writer(newUser.getUserName() + ".txt");
}