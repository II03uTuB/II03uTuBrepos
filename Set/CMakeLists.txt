cmake_minimum_required(VERSION 3.13)
project(Set)

set(CMAKE_CXX_STANDARD 14)

add_executable(Set tests/main.cpp 
                   tests/testsChar.cpp 
                   tests/testsDouble.cpp 
                   tests/testsInt.cpp
                   tests/testsThor.cpp)

add_library(Thor src/Thor.cpp)

target_link_libraries(Set Thor gtest gmock pthread)