### yejoon: shared library using in MSVC
if(true) 
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

cmake_minimum_required(VERSION 2.8)
project(chapter3)

set(CMAKE_CXX_FLAGS "-std=c++11")

# Add each sub-project
add_subdirectory(useEigen)
add_subdirectory(useGeometry)
add_subdirectory(visualizeGeometry)
add_subdirectory(examples)
