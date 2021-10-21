cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD  14)

project(firstLibCall)

include_directories(../firstLib/include)

add_executable(firstLibCall main.cpp)

target_link_libraries(firstLibCall firstLib)