cmake_minimum_required(VERSION 3.13)
project(Parking)

set(CMAKE_CXX_STANDARD 14)

add_library(Parking_Lib SHARED src/Parking.cpp)

add_executable(Parking tests/main.cpp tests/tests.cpp)

target_link_libraries(Parking Parking_Lib gtest gmock pthread)