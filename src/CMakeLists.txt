cmake_minimum_required(VERSION 3.17)
project(ascii_table)

set(CMAKE_CXX_STANDARD 14)

add_library(ascii_table table.h table.cpp column_info.h)
target_include_directories(ascii_table PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
