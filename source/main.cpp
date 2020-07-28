#include <iostream>
#include <list>

#include "clang-c/Index.h"

using namespace std;

ostream& operator<<(ostream& stream, const CXString& str)
{
    stream << clang_getCString(str);
    clang_disposeString(str);
    return stream;
}

int main(int argc, char **argv)
{
    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit unit;
    CXCursor cursor;

    unit = clang_parseTranslationUnit(index, "test/test-files/basic-test.c", nullptr, 0, nullptr, 0, CXTranslationUnit_None);

    if (unit == nullptr) {
        cout << "Unable to parse translation unit..." << endl;
        return 1;
    }

    cursor = clang_getTranslationUnitCursor(unit);

    clang_visitChildren(cursor, [](CXCursor c, CXCursor parent, CXClientData client_data) {
        CXString c_spelling_kind;
        const char *c_spelling = clang_getCString((c_spelling_kind = clang_getCursorSpelling(c)));
        const char *ck_spelling = clang_getCString(clang_getCursorKindSpelling(clang_getCursorKind(c)));

        cout << "Cursor:\t'" << c_spelling << "'\n";
        cout << "Kind:\t'" << ck_spelling << "'\n\n";

        clang_disposeString(c_spelling_kind);

        return CXChildVisit_Recurse;
    }, nullptr);

    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);
    return 0;
}
