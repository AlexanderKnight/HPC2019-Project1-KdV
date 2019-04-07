
cmake_minimum_required (VERSION 3.9)

project (KdV)

find_package(OpenMP COMPONENTS C REQUIRED)
add_library(libkdv kdv.h main.cpp func.c rk4.c timestep.c)
target_compile_features(libkdv PUBLIC c_std_99)
target_link_libraries(libkdv PUBLIC m)
target_link_libraries(libkdv PUBLIC OpenMP::OpenMP_C)

add_executable(kdv main.cpp)
target_compile_features(kdv PUBLIC c_std_99)
target_link_libraries(kdv libkdv)
