cmake_minimum_required(VERSION 3.20)
project(Odtwarzacz)

set(CMAKE_CXX_STANDARD 14)

add_executable(Odtwarzacz src/main.cpp include/Music.h src/Music.cpp)