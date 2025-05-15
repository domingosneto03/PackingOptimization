cmake_minimum_required(VERSION 3.30)
project(da_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(da_project2 main.cpp
        Reader.h
        Menu.cpp
        Menu.h
        BruteForceSolver.cpp
        BruteForceSolver.h
)
