cmake_minimum_required(VERSION 3.24)
project(KLang__)

set(CMAKE_CXX_STANDARD 20)

add_executable(KLang__ src/main.cpp include/Position.h include/Error.h src/Error.cpp include/Token.h src/Position.cpp src/Token.cpp include/Lexer.h src/Lexer.cpp)
