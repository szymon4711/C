cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(firstLib STATIC src/lib.cpp)