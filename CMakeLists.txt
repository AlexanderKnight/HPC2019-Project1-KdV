
cmake_minimum_required (VERSION 3.9)

project (KdV)

find_package(OpenMP COMPONENTS C REQUIRED)
add_library(libkdv kdv.h main.cpp func.cpp rk4.cpp)
target_compile_features(libkdv PUBLIC c_std_99)
target_link_libraries(libkdv PUBLIC m)
target_link_libraries(libkdv PUBLIC OpenMP::OpenMP_C)

add_library(libinit initFunc.h init_functions.cpp kdv_func_gen.cpp)
target_link_libraries(libinit PUBLIC m)

add_executable(kdv main.cpp)
target_compile_features(kdv PUBLIC c_std_99)
target_link_libraries(kdv libkdv)

add_executable(initData kdv_func_gen.cpp)
target_link_libraries(initData libinit)
