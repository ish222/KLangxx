#ifndef KLANG___TOKEN_H
#define KLANG___TOKEN_H

#include <cstdint>

enum class TokenType : uint8_t {
    Invalid = 0,
    Int = 1,
    Float = 2,
    Plus = 3,
    Minus = 4,
    Mul = 5,
    Div = 6,
    Eq = 7,
    EOF = 8,
    Count = 9
};

class Token {
public:

protected:

};

#endif//KLANG___TOKEN_H
