cmake_minimum_required(VERSION 3.13)
project(STLAlgo)

set(CMAKE_CXX_STANDARD 14)

add_library(STLAlgo_Lib src/STLAlgo.cpp )

add_executable(STLAlgo tests/main.cpp tests/tests.cpp)

target_link_libraries(STLAlgo STLAlgo_Lib gtest gmock pthread)