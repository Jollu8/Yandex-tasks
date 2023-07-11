cmake_minimum_required(VERSION 3.20)
project(russiantests)
add_executable(backend2023_a InternSpringAutmn2023BackEnd/A.cpp)
set_target_properties(backend2023_a PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )
add_executable(backend2023_b InternSpringAutmn2023BackEnd/B.cpp)
set_target_properties(backend2023_b PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )

add_executable(backend2023_d InternSpringAutmn2023BackEnd/D.cpp)
set_target_properties(backend2023_d PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )