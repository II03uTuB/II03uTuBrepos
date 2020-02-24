cmake_minimum_required(VERSION 3.13)
project(Maze)

set(CMAKE_CXX_STANDARD 14)

add_library(Maze_Lib src/Maze.cpp)

add_executable(Maze tests/main.cpp tests/tests.cpp)

target_link_libraries(Maze Maze_Lib gtest gmock pthread)