cmake_minimum_required(VERSION 3.19)
project(simpleCalc)

set(CMAKE_CXX_STANDARD 14)

add_executable(simpleCalc include/Calc.h src/calc.cpp src/main.cpp)