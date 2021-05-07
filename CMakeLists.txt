cmake_minimum_required(VERSION 3.21)
project(basic_visitor_pattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(basic_visitor_pattern main.cpp app_animal_visitor.hpp animal_library.hpp)
