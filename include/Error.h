#ifndef KLANG_ERROR_H
#define KLANG_ERROR_H

#include "Position.h"
#include <array>
#include <string>

enum class ErrorType : uint8_t {
    None = 0,
    IllegalCharError = 1,
    InvalidSyntaxError = 2,
    RuntimeError = 3,
    ErrorCount = 4
};

class Error {
public:
    Error() = default;
    Error(const Position& pos_start, const Position& pos_end, ErrorType errorType, std::string details)
        : _start(pos_start), _end(pos_end), _err(errorType), _details(std::move(details)) {}
    virtual ~Error() = default;

    Error(const Error& other) = default;
    Error& operator=(const Error& other) = default;

    [[nodiscard]] virtual std::string message() const;

protected:
    std::string _details{};
    Position _start{};
    Position _end{};
    ErrorType _err{};

    std::array<std::string, static_cast<std::size_t>(ErrorType::ErrorCount) + 1> ErrorTypeToStr = {
            "None", "IllegalCharError", "InvalidSyntaxError", "RuntimeError", "ErrorCount"};

    static std::string beautify_string(const std::string& text, const Position& pos_start, const Position& pos_end);
};

class IllegalCharError : public Error {
public:
    IllegalCharError(const Position& pos_start, const Position& pos_end, std::string details)
        : Error(pos_start, pos_end, ErrorType::IllegalCharError, std::move(details)) {}
};

class InvalidSyntaxError : public Error {
public:
    InvalidSyntaxError(const Position& pos_start, const Position& pos_end, std::string details)
        : Error(pos_start, pos_end, ErrorType::InvalidSyntaxError, std::move(details)) {}
};

#endif//KLANG_ERROR_H
