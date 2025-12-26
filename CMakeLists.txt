cmake_minimum_required(VERSION 3.31)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA
        "Dynamic Programming/0_1_knapback.cpp"
        solution_checking.cpp
        "Dynamic Programming/0_1_knapback_scroll.cpp"
        "Dynamic Programming/lcs_string.cpp"
)
