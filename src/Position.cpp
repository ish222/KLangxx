#include "../include/Position.h"

Position& Position::advance(char current_char) {
    ++_index;
    ++_col;

    if (current_char == '\n') {
        ++_line;
        _col = 0;
    }

    return *this;
}
