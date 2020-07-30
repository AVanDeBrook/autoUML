#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <list>
#include <exception>

#include "clang-c/Index.h"
#include "FunctionObj/FunctionObj.hpp"

using namespace std;

class Parser {
    private:
        /****** Private Class Attributes ******/
        CXIndex index;
        CXTranslationUnit unit;
        list<FunctionObj> functionList;
        string sourceFile;

        /****** Private Member Functions ******/
        FunctionObj *allocFunctionObj(void);
        void printFunctionList(void);

    public:
        /****** Constructor(s) / Deconstructor ******/
        Parser(string fileName);
        ~Parser();

        /****** Public Member Functions ******/
        void parse(bool verbose);

        /****** Accessor Functions ******/
        string getSourceFile(void);
        void setSourceFile(string fileName);
};
#endif
