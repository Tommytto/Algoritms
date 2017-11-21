cmake_minimum_required(VERSION 3.8)
project(CourseWork)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(/usr/include/)
link_directories(/usr/include/)

set(SOURCE_FILES main.cpp Task.cpp Task.h Processor.cpp Processor.h Stack.cpp Stack.h Queue.cpp Queue.h)
add_executable(CourseWork ${SOURCE_FILES})