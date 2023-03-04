#include "../include/Error.h"

std::string Error::message() const {
    std::string message = ErrorTypeToStr[static_cast<std::size_t>(_err)] + ": " + _details;
    message += "\nFile " + _start.get_fileName() + ", line " + std::to_string(_start.get_line() + 1);
    message += "\n\n" + beautify_string(_start.get_fileText(), _start, _end);
    return message;
}

std::string Error::beautify_string(const std::string& text, const Position& pos_start, const Position& pos_end) {
    std::string result;

    // Calculate the indices
    size_t found = text.rfind('\n', pos_start.get_index());
    size_t index_start = found != std::string::npos ? found : 0U;

    size_t index_end = text.find('\n', index_start+1);
    if (index_end == std::string::npos)
        index_end = text.size();

    // Generate each line
    size_t line_count = pos_end.get_line() - pos_start.get_line() + 1;
    for (size_t i = 0; i < line_count; ++i) {
        // Calculate line columns
        std::string line = text.substr(index_start, (index_end - index_start - 1));
        size_t col_start = i == 0 ? pos_start.get_col() : 0;
        size_t col_end = i == (line_count - 1) ? pos_end.get_col() : line.size() - 1;

        // Append to result
        result += line + '\n';
        result += std::string(col_start, ' ') + std::string((col_end - col_start), '^');

        // Recalculate indices
        index_start = index_end;
        index_end = text.find('\n', index_start+1);
        if (index_end == std::string::npos)
            index_end = text.size();
    }

    result.erase(std::remove(result.begin(), result.end(), '\t'), result.end());
    return result;
}
