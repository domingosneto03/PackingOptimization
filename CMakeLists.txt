cmake_minimum_required(VERSION 3.30)
project(da_project2)

set(CMAKE_CXX_STANDARD 20)

# OR-Tools location
set(ORTOOLS_PATH "C:/Users/domin/Faculdade/2Ano/DA/24_25/or-tools_x64_VisualStudio2022_cpp_v9.11.4210")  # Change this if needed

# Include and lib paths
include_directories(${ORTOOLS_PATH}/include)
link_directories(${ORTOOLS_PATH}/lib)

add_executable(da_project2 main.cpp
        Reader.h
        Menu.cpp
        Menu.h
        BruteForceSolver.cpp
        BruteForceSolver.h
        DynamicSolver.cpp
        GreedySolver.cpp
        ILPSolver.cpp
        ILPSolver.h
)

target_link_libraries(da_project2 ortools)