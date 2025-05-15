cmake_minimum_required(VERSION 3.10)
project(CTestDemo)

# set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_library(mylib mylib.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)