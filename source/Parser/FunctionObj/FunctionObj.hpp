#ifndef FUNCTIONOBJ_HPP
#define FUNCTIONOBJ_HPP

#include <string>

using namespace std;

class FunctionObj {
    private:
        /****** Private Class Attributes ******/
        string s_type;
        string s_name;

    public:
        /****** Constructor/Deconstructor(s) ******/
        FunctionObj(string type, string name);
        FunctionObj();

        /****** Accessor Functions ******/
        void setType(string type);
        void setName(string name);
        string getType(void);
        string getName(void);
};

#endif