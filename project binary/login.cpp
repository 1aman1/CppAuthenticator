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

class PersistanceManager_t
{
public:
    static bool save(const user_t &userObj, std::string filename);
};

/*
    forward declaration above
*/

class userRegistration_t
{

public:
    void interface();
    bool registerNewUserAccount();
    bool login();
    bool logout();
};

bool userRegistration_t::registerNewUserAccount()
{
    std::string userName;
    std::cout << "username(case-insensitive)\n";
    std::cin >> userName;

    bool matchPass = true;
    std::string password, confirmpassword;

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

    // VALID INPUT ^

    /*
    we check if the username is new, only then we proceed
    */

    std::fstream ifs;
    std::string filename = "userDataStore/" + userName + ".utext";

    ifs.open(filename);
    if (ifs.is_open())
    {
        std::cerr << "user already present with this ID";
        return false;
    }

    // VALID USER ^

    // we have details, now data persistence procedure
    // write data provided in a file and save the file

    if (PersistanceManager_t::save(user_t(userName, password), userName + ".utext"))
        std::cout << "saved !\n";
    else
        std::cout << "could not save !\n";
}

bool userRegistration_t::login()
{
    std::cerr << "under maintenance\n";
    return false;

    std::string username;
    std::cin >> username;

    // try loading the file, if same username exists, return
    // else
    // {
    //     // match password
    // }
}

bool userRegistration_t::logout()
{
    std::cerr << "under maintenance\n";
    return false;
}

void userRegistration_t::interface()
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
            if (registerNewUserAccount())
                std::cout << "registered!!\n";
            else
                std::cerr << "failed!\n";
        }
        break;

        case 2:
        {
            if (login())
                std::cout << "Logged In\n";
            else
                std::cerr << "Login failed!\n";
        }
        break;

        case 3:
        {
            if (logout())
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