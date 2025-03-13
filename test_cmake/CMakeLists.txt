cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(Mylib src/myLib.cpp)
add_executable(MyExecutable src/main.cpp)

target_link_libraries(MyExecutable Mylib)