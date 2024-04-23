cmake_minimum_required(VERSION 2.8)

project(useEigen)

set(CMAKE_BUILD_TYPE "Release") 
set(CMAKE_CXX_FLAGS "-O3")

# Add Eigen header files

add_executable(eigenMatrix eigenMatrix.cpp)
### yejoon: window Eigen-3 directory : using vcpkg and CMAKE_TOOLCHAIN_FILE
find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(eigenMatrix Eigen3::Eigen)
