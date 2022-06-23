#ifndef iam_h
#define iam_h

// header guard above
#include <string>

class auth_t
{
public:
    void interface();
    bool registerNew();
    bool loginUser();
    bool logoutUser();
    bool ifUserExists(std::string);
};

#endif
