cmake_minimum_required(VERSION 3.13)
project(BinarySearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinarySearch tests/main.cpp tests/tests.cpp)

target_link_libraries(BinarySearch gtest gmock pthread)
