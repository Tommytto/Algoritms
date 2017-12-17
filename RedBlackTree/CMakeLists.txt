cmake_minimum_required(VERSION 3.8)
project(RedBlackTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h Product.cpp Product.h MapItem.cpp MapItem.h)
add_executable(RedBlackTree ${SOURCE_FILES})