cmake_minimum_required(VERSION 3.0.0)
project(Let10Stack)

set(CMAKE_CXX_STANDARD 11)

add_library(Let10Stack.Lib src/IntStack.cpp)
add_executable(Let10Stack tests/main.cpp tests/stacktests.cpp)

target_link_libraries(Let10Stack Let10Stack.Lib gtest gmock pthread)
