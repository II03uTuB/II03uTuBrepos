cmake_minimum_required(VERSION 3.13)
project(AbstractFactory)

set (CMAKE_CXX_STANDARD 14)

add_library(AbstractFactory_Lib src/CurrencyFactory.cpp src/Dollar.cpp src/Euro.cpp)

add_executable(AbstractFactory tests/main.cpp tests/tests.cpp)

target_link_libraries(AbstractFactory AbstractFactory_Lib gtest gmock pthread)
