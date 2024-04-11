cmake_minimum_required(VERSION 2.8)
### yejoon: shared library using in MSVC
if(true)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

project(useEigen)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-O3")

# Add Eigen header files
include_directories("/usr/include/eigen3")
add_executable(eigenMatrix eigenMatrix.cpp)
