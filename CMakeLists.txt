cmake_minimum_required(VERSION 3.10)
project(Mypocket)

set(CMAKE_CXX_STANDARD 11)


find_package(pybind11 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(4dpocket)