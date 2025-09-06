cmake_minimum_required(VERSION 3.10)
project(MathUtilsConsumer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the library (now with 'lib' prefix)
find_library(MATH_UTILS_LIB libMathUtils 
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_library/build/bin/Release
    HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_library/build/lib/Release
)

# Add executable
add_executable(MathUtilsConsumer src/main.cpp)

# Link to the library and include its headers
target_include_directories(MathUtilsConsumer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_library/include
)

target_link_libraries(MathUtilsConsumer PRIVATE ${MATH_UTILS_LIB})

if(WIN32)
    add_custom_command(TARGET MathUtilsConsumer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_library/build/bin/Release/libMathUtils.dll"
            $<TARGET_FILE_DIR:MathUtilsConsumer>
    )
endif()
