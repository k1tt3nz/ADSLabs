cmake_minimum_required(VERSION 3.23)
project(ADSLabs C)

set(CMAKE_C_STANDARD 11)

add_executable(ADSLabs main.c)
include_directories(libs/DataStructs/sort)
include_directories(libs/DataStructs/string)
include_directories(libs/DataStructs/stack)
include_directories(libs/test)
