cmake_minimum_required(VERSION 3.15)
project(pluslearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(myprog
    headers/main.cpp
    headers/Student.cpp
)

target_include_directories(myprog
    PUBLIC
        headers/
)