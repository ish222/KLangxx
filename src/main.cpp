#include <iostream>
#include "../include/Lexer.h"



int main() {
    std::string line;
    while (true) {
        std::cout << "\nbasic > ";
        std::getline(std::cin, line);
        Lexer lexer("<stdin>", line);
        Lexer::LexerResult result = lexer.makeTokens();
        if (result.error)
            std::cout << result.error->message() << std::endl;
        else {
            for (const auto& i : result.TokenList) {
                std::cout << i << '\n';
            }
        }
    }
    return 0;
}
