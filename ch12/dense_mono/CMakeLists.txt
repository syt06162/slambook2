cmake_minimum_required(VERSION 2.8)
project(dense_monocular)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3")

############### dependencies ######################
# Eigen
### yejoon: window Eigen-3 directory
include(${CMAKE_SOURCE_DIR}/../YejoonPathConfig.cmake)
include_directories(${EIGEN_INCLUDE_DIR})
# OpenCV
find_package(OpenCV 3.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# Sophus
find_package(Sophus REQUIRED)
include_directories(${Sophus_INCLUDE_DIRS})

set(THIRD_PARTY_LIBS
        ${OpenCV_LIBS}
        ${Sophus_LIBRARIES})

add_executable(dense_mapping dense_mapping.cpp)
target_link_libraries(dense_mapping ${THIRD_PARTY_LIBS})