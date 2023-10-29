#ifndef OBJ_ATTR_H
#define OBJ_ATTR_H

#include <string>

class ObjectAttribute
{
public:
    static std::string getAbsolutePath(std::string username);

private:
    static std::string directory;
    static std::string extension;
};

#endif
