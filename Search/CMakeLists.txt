cmake_minimum_required(VERSION 3.8)
project(Search)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AlgoritmsInSorted.cpp AlgoritmsInSorted.h AlgoritmsInUnsorted.cpp AlgoritmsInUnsorted.h)
add_executable(Search ${SOURCE_FILES})