cmake_minimum_required(VERSION 3.13)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList tests/main.cpp tests/tests.cpp)

target_link_libraries(LinkedList gtest gmock pthread)