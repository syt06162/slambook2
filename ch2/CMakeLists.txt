# Declare the required cmake minimum version
cmake_minimum_required(VERSION 2.8)

# yejoon: shared library using in MSVC
if(true)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

# Declare a cmake project
project(HelloSLAM)

# Set the build mode
set(CMAKE_BUILD_TYPE "Debug")

# Add an executable
# Syntax: add_executable( executable_name source_code_file )
add_executable(helloSLAM helloSLAM.cpp)



# Add the hello library
## add_library(hello libHelloSLAM.cpp)

# Shared library
add_library(hello_shared SHARED libHelloSLAM.cpp)

# Add an executable to call functions from the hello library
add_executable(useHello useHello.cpp)
# Link the library file to the executable
target_link_libraries(useHello hello_shared)
