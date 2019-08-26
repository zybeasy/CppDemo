cmake_minimum_required(VERSION 3.14)
project(CppDemo)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppDemo main.cpp tree/bin_tree.cpp tree/traverse.cpp tree/traverse.h sword/utils/Array.h sword/utils/Array.cpp sword/utils/List.h sword/utils/List.cpp sword/chapter_2.cpp sword/chapter_2.h test.h test.cpp sort/sort.cpp sort/sort.h)
