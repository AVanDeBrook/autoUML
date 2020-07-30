#include "Parser.hpp"

#include "clang-c/Index.h"

static list<FunctionObj> f_list;

/****** Constructor/Deconstructor(s) ******/
Parser::Parser(string fileName)
{
    sourceFile = fileName;
    index = clang_createIndex(0, 0);
}

Parser::~Parser()
{
    clang_disposeIndex(index);
    clang_disposeTranslationUnit(unit);

    for (FunctionObj f : functionList) {
        free(&f);
    }
}

/****** Private Member Functions ******/
CXChildVisitResult cursorTreeWalker(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
    FunctionObj *temp_obj = new FunctionObj();
    CXString cursorSpelling = clang_getCursorSpelling(cursor);
    CXString cursorTypeSpelling = clang_getTypeSpelling(clang_getCursorType(cursor));

    if (clang_isDeclaration(clang_getCursorKind(cursor))) {
        temp_obj->setName(clang_getCString(cursorSpelling));
        temp_obj->setType(clang_getCString(cursorTypeSpelling));
        f_list.push_back(*temp_obj);
    }

    clang_disposeString(cursorSpelling);
    clang_disposeString(cursorTypeSpelling);

    return CXChildVisit_Recurse;
}

void Parser::printFunctionList(void)
{
    for (FunctionObj f : functionList) {
        std::cout << f.getName() << "\t" << f.getType() << std::endl;
    }
}

/****** Public Member Functions ******/
void Parser::parse(bool verbose)
{
    unit = clang_parseTranslationUnit(index, sourceFile.c_str(), nullptr, 0, nullptr, 0, CXTranslationUnit_None);
    CXCursor cursor = clang_getTranslationUnitCursor(unit);

    if (unit == nullptr) {
        std::cerr << "Could not parse source file: " << sourceFile << std::endl;
        return;
    }

    clang_visitChildren(cursor, cursorTreeWalker, nullptr);

    // TODO: Bit of a hack, fix later
    for (FunctionObj f : f_list) {
        functionList.push_back(f);
    }

    if (verbose) {
        printFunctionList();
    }
}

/****** Accessor Functions ******/
string Parser::getSourceFile(void)
{
    return sourceFile;
}

void Parser::setSourceFile(string fileName)
{
    sourceFile = fileName;
}
