cmake_minimum_required(VERSION 3.14)
project(CppDemo)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppDemo main.cpp tree/bin_tree.cpp tree/traverse.cpp tree/traverse.h)
