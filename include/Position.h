#ifndef KLANG_POSITION_H
#define KLANG_POSITION_H

#include <cstddef>
#include <string>

class Position {
public:
    Position() = default;

    Position(const size_t& index, const size_t& line, const size_t& col, std::string fileName,
             std::string fileText) : _index(index), _line(line), _col(col), _fileName(std::move(fileName)),
                                            _fileText(std::move(fileText)) {}

    Position(const Position& other) = default;
    Position& operator=(const Position& other) = default;

    void set_index(const size_t& index) { _index = index; }
    void set_line(const size_t& line) { _line = line; }
    void set_col(const size_t& col) { _col = col; }
    void set_fileName(const std::string& fileName) { _fileName = fileName; }
    void set_fileText(const std::string& fileText) { _fileText = fileText; }

    [[nodiscard]] size_t get_index() const { return _index; }
    [[nodiscard]] size_t get_line() const { return _line; }
    [[nodiscard]] size_t get_col() const { return _col; }
    [[nodiscard]] std::string get_fileName() const { return _fileName; }
    [[nodiscard]] std::string get_fileText() const { return _fileText; }

    Position& advance(char current_char = '\0');

private:
    size_t _index{};
    size_t _line{};
    size_t _col{};
    std::string _fileName;
    std::string _fileText;
};

#endif//KLANG_POSITION_H
