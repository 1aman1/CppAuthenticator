#ifndef obj_attr_h
#define obj_attr_h

#include <string>

class objAttribute_t
{
public:
    // objAttribute_t();
    static std::string location;
    static std::string ufoExtension;
    
    static std::string getFile(std::string);
    static std::string getAbsFile(std::string);
};

#endif