cmake_minimum_required(VERSION 3.13)
project(ForwardList)

set (CMAKE_CXX_STANDARD 14)

add_executable(ForwardList tests/main.cpp tests/tests.cpp)

target_link_libraries(ForwardList gtest gmock pthread)
