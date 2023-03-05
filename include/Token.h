#ifndef KLANG___TOKEN_H
#define KLANG___TOKEN_H

#include <array>
#include <cstdint>
#include <string>

enum class TokenType : uint8_t {
    Invalid = 0,
    Int = 1,
    Float = 2,
    Plus = 3,
    Minus = 4,
    Mul = 5,
    Div = 6,
    Eq = 7,
    _EOF = 8,
    Count = 9
};

class Token {
public:
    Token() = default;
    explicit Token(TokenType type, std::string value = "")
            : _type(type), _value(std::move(value)) {}
    virtual ~Token() = default;

    [[nodiscard]] std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Token& token);

protected:
    TokenType _type{TokenType::Count};
    std::string _value;

    std::array<std::string, static_cast<std::size_t>(TokenType::Count) + 1> TokenTypeToStr = {
            "Invalid",
            "Int",
            "Float",
            "Plus",
            "Minus",
            "Mul",
            "Div",
            "Eq",
            "EOF",
            "Count"
    };
};

#endif//KLANG___TOKEN_H
