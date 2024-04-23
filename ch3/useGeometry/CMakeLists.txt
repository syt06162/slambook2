cmake_minimum_required( VERSION 2.8 )
project( geometry )

# Add Eigen header files
### yejoon: window Eigen-3 directory
# include(${CMAKE_SOURCE_DIR}/../YejoonPathConfig.cmake)
# include_directories(${EIGEN_INCLUDE_DIR})

find_package(Eigen3 CONFIG REQUIRED)
add_executable(eigenGeometry eigenGeometry.cpp)
target_link_libraries(eigenGeometry Eigen3::Eigen)
