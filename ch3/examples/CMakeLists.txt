### yejoon: window Eigen-3 directory
# include(${CMAKE_SOURCE_DIR}/../YejoonPathConfig.cmake)
# include_directories(${EIGEN_INCLUDE_DIR})

add_executable(coordinateTransform coordinateTransform.cpp)

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
add_executable(plotTrajectory plotTrajectory.cpp)
target_link_libraries(plotTrajectory ${Pangolin_LIBRARIES})

### yejoon: window Eigen-3 directory : using vcpkg and CMAKE_TOOLCHAIN_FILE
find_package(Eigen3 CONFIG REQUIRED)
target_link_libraries(coordinateTransform Eigen3::Eigen)
target_link_libraries(plotTrajectory Eigen3::Eigen)
