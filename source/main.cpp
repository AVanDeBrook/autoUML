#include <iostream>

#include "Parser/Parser.hpp"

int main(int argc, char **argv)
{
    string fileList[] = {
        "test/test-files/basic-test.c",
        "test/test-files/test.c",
        "test/test-files/test.h"
    };
    Parser *parser_objs[3];

    for (int i = 0; i < 3; i++) {
        parser_objs[i] = new Parser(fileList[i]);
        std::cout << fileList[i] << std::endl;
        parser_objs[i]->parse(true);
        std::cout << std::endl;
    }

    return 0;
}
