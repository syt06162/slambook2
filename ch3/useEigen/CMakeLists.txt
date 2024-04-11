cmake_minimum_required(VERSION 2.8)

project(useEigen)

set(CMAKE_BUILD_TYPE "Release") 
set(CMAKE_CXX_FLAGS "-O3")

# Add Eigen header files
### yejoon: window Eigen-3 directory
include_directories("D:/c-workspace/Dependencies/eigen-3.4.0")
add_executable(eigenMatrix eigenMatrix.cpp)
