cmake_minimum_required(VERSION 3.17)
project(hw17)

set(CMAKE_CXX_STANDARD 11)

add_library(qs chapter7/quicksort_717.h chapter7/quicksort_717.cpp)

add_executable(main main.cpp)
target_link_libraries(main qs)