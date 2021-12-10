cmake_minimum_required(VERSION 3.21)
project(nhf2)

set(CMAKE_CXX_STANDARD 20)

add_executable(nhf2 main.cpp ternary_app.h ternary_app.cpp ternary_node.h ternary_tree.h ternary_tree.cpp binary_node.h binary_tree.h binary_tree.cpp)
