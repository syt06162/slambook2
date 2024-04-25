cmake_minimum_required(VERSION 2.8)
project(visualizeGeometry)


# yejoon: c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add Eigen header files
### yejoon: window Eigen-3 directory
include(${CMAKE_SOURCE_DIR}/../YejoonPathConfig.cmake)
include_directories(${EIGEN_INCLUDE_DIR})

# Add Pangolin dependency
find_package(Pangolin)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(visualizeGeometry visualizeGeometry.cpp)
target_link_libraries(visualizeGeometry ${Pangolin_LIBRARIES})
