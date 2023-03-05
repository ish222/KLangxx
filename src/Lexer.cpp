#include "../include/Lexer.h"

void Lexer::advance() {
    _pos.advance(_currentChar);
    _currentChar = _pos.get_index() < _text.size() ? _text[_pos.get_index()] : '\0';
}

Lexer::LexerResult Lexer::makeTokens() {
    std::vector<Token> tokens;
    _currentChar = _text.empty() ? '\0' : _text[0];
    while(_currentChar != '\0') {
        switch (_currentChar) {
            case ' ':
            case '\t':
                advance();
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tokens.push_back(getNumber());
                break;
            case '+':
                tokens.emplace_back(TokenType::Plus);
                advance();
                break;
            case '-':
                tokens.emplace_back(TokenType::Minus);
                advance();
                break;
            case '*':
                tokens.emplace_back(TokenType::Mul);
                advance();
                break;
            case '/':
                tokens.emplace_back(TokenType::Div);
                advance();
                break;
            default:
            {
                Position pos_start =  Position(_pos);
                char char_cpy = _currentChar;
                advance();
                return LexerResult{{}, new IllegalCharError(pos_start, _pos, "'"+std::to_string(char_cpy)+"'")};
            }
        }
    }

    return {tokens, nullptr};
}

Token Lexer::getNumber() {
    std::string num_str;
    uint8_t dot_count = 0;

    while (_currentChar != '\0' && DIGITS_DOT.find(_currentChar) != std::string::npos) {
        if (_currentChar == '.') {
            if (dot_count == 1)
                break;
            ++dot_count;
            num_str += '.';
        } else num_str += _currentChar;
        advance();
    }

    if (dot_count == 0)
        return Token(TokenType::Int, num_str);
    else return Token(TokenType::Float, num_str);
}
