#include <iostream>
#include "AST.h"

int main()
{
    std::cout << "> ";
    std::string line;
    while(true) {
        AST* ast = nullptr;
        std::getline(std::cin, line);
        ast = AST::parse(line);

        std::cout << ast -> value() << '\n';
        std::cout << ast -> prefix() << '\n';
        std::cout << ast -> postfix() << '\n';
    }
    return 0;
}