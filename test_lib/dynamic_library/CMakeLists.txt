cmake_minimum_required(VERSION 3.10)
project(MathUtils)

# Set library prefixes to 'lib'
set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
set(CMAKE_IMPORT_LIBRARY_PREFIX "lib")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library configuration
add_library(MathUtils SHARED 
    src/math_utils.cpp
    include/math_utils.h
)

target_include_directories(MathUtils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# For MSVC, define the export macro
if(MSVC)
    target_compile_definitions(MathUtils PRIVATE MATHUTILS_EXPORTS)
endif()

# Set output directory for the DLL
set_target_properties(MathUtils PROPERTIES 
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    PREFIX "lib"  # Ensures the output files start with 'lib'
    OUTPUT_NAME "MathUtils"  # Base name without prefix or extension
)
