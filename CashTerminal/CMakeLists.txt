cmake_minimum_required(VERSION 3.13)
project(CashTerminal)

set (CMAKE_CXX_STANDARD 14)

add_library(CashTerminal_Lib src/CashTerminal.cpp)

add_executable(CashTerminal tests/main.cpp tests/tests.cpp)

target_link_libraries(CashTerminal CashTerminal_Lib gtest gmock pthread)
