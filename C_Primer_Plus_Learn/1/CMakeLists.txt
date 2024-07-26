cmake_minimum_required(VERSION 3.10)
project(CPP_Primer_1)
set(CMAKE_CXX_STANDARD_DEFAULT 11)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(CPP_Primer_1 main.cpp)