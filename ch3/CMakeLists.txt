
cmake_minimum_required(VERSION 3.21)
project(chapter3)

### yejoon: shared library using in MSVC
if(MSVC) 
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

set(CMAKE_CXX_FLAGS "-std=c++11")

# Add each sub-project
add_subdirectory(useEigen)
add_subdirectory(useGeometry)

add_subdirectory(examples)
add_subdirectory(visualizeGeometry)

