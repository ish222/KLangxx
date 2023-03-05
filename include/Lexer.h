#ifndef KLANG___LEXER_H
#define KLANG___LEXER_H

#include "Error.h"
#include "Position.h"
#include "Token.h"
#include <string>
#include <vector>

static const std::string DIGITS_DOT = "1234567890.";

class Lexer {
public:
    struct LexerResult;

public:
    Lexer() = default;
    Lexer(std::string fileNmae, std::string text) : _fileName(std::move(fileNmae)), _text(std::move(text)) {}
    virtual ~Lexer() = default;

    void advance();
    LexerResult makeTokens();
    Token getNumber();

public:
    struct LexerResult {
        std::vector<Token> TokenList;
        Error* error{nullptr};

        LexerResult(std::vector<Token> tokenList, Error* err) : TokenList(std::move(tokenList)), error(err) {}
        ~LexerResult() = default;
    };

protected:
    std::string _fileName;
    std::string _text;
    Position _pos{0,0,0,_fileName,_text};
    char _currentChar;
};

#endif//KLANG___LEXER_H
