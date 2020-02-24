cmake_minimum_required(VERSION 3.13)
project(IMilitaryMan)

set(CMAKE_CXX_STANDARD 11)

add_executable(IMilitaryMan tests/main.cpp tests/tests.cpp)

add_library(IMilitaryMan.Lib src/Officer.cpp src/Soldier.cpp)

target_link_libraries(IMilitaryMan IMilitaryMan.Lib gtest gmock pthread)