#include "FunctionObj.hpp"

/****** Constructor/Deconstructor(s) ******/
FunctionObj::FunctionObj(string type, string name)
{
    s_type = type;
    s_name = name;
}

FunctionObj::FunctionObj()
{
    s_type = "";
    s_name = "";
}

/****** Accessor Functions ******/
void FunctionObj::setType(string type)
{
    s_type = type;
}

void FunctionObj::setName(string name)
{
    s_name = name;
}

string FunctionObj::getType(void)
{
    return s_type;
}

string FunctionObj::getName(void)
{
    return s_name;
}
