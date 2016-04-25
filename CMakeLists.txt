cmake_minimum_required(VERSION 3.5)
project(nkVector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp nkVector.h nkVector.cpp)
add_executable(nkVector ${SOURCE_FILES})