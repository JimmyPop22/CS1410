cmake_minimum_required(VERSION 3.20)
project(cpp_starter_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main src/main.cpp)
add_executable(ex0101 src/ex0101.cpp)
add_executable(ex0102 src/ex0102.cpp)
add_executable(ex0201 src/ex0201.cpp)
add_executable(ex0202 src/ex0202.cpp)
add_executable(ex0203 src/ex0203.cpp)