#include "../include/Token.h"

std::string Token::toString() const {
    if (!_value.empty())
        return TokenTypeToStr[(std::size_t)_type] + ":" + _value;
    return TokenTypeToStr[(std::size_t)_type];
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << token.toString();
    return os;
}