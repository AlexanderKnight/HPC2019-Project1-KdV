
cmake_minimum_required (VERSION 3.9)

project (KdV)

find_package(OpenMP COMPONENTS C REQUIRED)

add_library(libkdv kdv.h main.cpp func.cpp rk4.cpp)
target_compile_features(libkdv PUBLIC c_std_99)
target_link_libraries(libkdv PUBLIC m)
#target_link_libraries(libkdv OpenMP::OpenMP_C)

add_library(libinit init.h init_funcs.cpp init_func_gen.cpp)
target_link_libraries(libinit PUBLIC m)

add_executable(kdv main.cpp)
target_compile_features(kdv PUBLIC c_std_99)
target_link_libraries(kdv libkdv OpenMP::OpenMP_C)

add_executable(init_data init_func_gen.cpp)
target_link_libraries(init_data libinit)
