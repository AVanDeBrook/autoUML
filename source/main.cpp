#include <iostream>
#include <list>
#include <string>

#include "clang-c/Index.h"

using namespace std;

static list<string> function_list;

int main(int argc, char **argv)
{
    CXIndex index = clang_createIndex(0, 0);
    CXTranslationUnit unit;
    CXCursor cursor;

    unit = clang_parseTranslationUnit(index, "test/test-files/test.c", nullptr, 0, nullptr, 0, CXTranslationUnit_None);

    if (unit == nullptr) {
        cout << "Unable to parse translation unit..." << endl;
        return 1;
    }

    cursor = clang_getTranslationUnitCursor(unit);

    clang_visitChildren(cursor, [](CXCursor c, CXCursor parent, CXClientData client_data) {
        CXCursorKind cursor_kind = clang_getCursorKind(c);
        CXString cursor_spelling = clang_getCursorSpelling(c);

        // Only add symbol names of functions (no vars, etc.)
        if (cursor_kind == CXCursor_FunctionDecl) {
            function_list.push_back(clang_getCString(cursor_spelling));
        }

        clang_disposeString(cursor_spelling);

        return CXChildVisit_Recurse;
    }, nullptr);

    cout << "Functions:" << endl;
    for (string s : function_list) {
        cout << s << endl;
    }

    clang_disposeTranslationUnit(unit);
    clang_disposeIndex(index);
    return 0;
}
