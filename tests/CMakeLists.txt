cmake_minimum_required(VERSION 3.17)
project(ascii_table_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(ascii_table_tests main.cpp)
add_library(ascii_table STATIC IMPORTED ../src/Table.h)
set_property(TARGET ascii_table PROPERTY IMPORTED_LOCATION "C:/Users/benny/CLionProjects/ascii-table/src/cmake-build-debug/libascii_table.a")
target_link_libraries(ascii_table_tests ascii_table)
