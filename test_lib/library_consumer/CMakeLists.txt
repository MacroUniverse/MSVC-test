cmake_minimum_required(VERSION 3.10)
project(MathUtilsConsumer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(MSVC_BUILD_TYPE BtDebug) # Release
set(MATH_UTILS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../dynamic_library)
set(MATH_UTILS_BUILD_PATH ${MATH_UTILS_PATH}/build-msvc)
message(STATUS ${MSVC_BUILD_TYPE})

# Find the library (now with 'lib' prefix)
find_library(MATH_UTILS_LIB NAMES libMathUtils 
    HINTS ${MATH_UTILS_BUILD_PATH}/bin/${MSVC_BUILD_TYPE}
    HINTS ${MATH_UTILS_BUILD_PATH}/lib/${MSVC_BUILD_TYPE}
)

# Add executable
add_executable(MathUtilsConsumer src/main.cpp)

# Link to the library and include its headers
target_include_directories(MathUtilsConsumer PRIVATE
    ${MATH_UTILS_PATH}/include
)

target_link_libraries(MathUtilsConsumer PRIVATE ${MATH_UTILS_LIB})

if(WIN32)
    add_custom_command(TARGET MathUtilsConsumer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${MATH_UTILS_BUILD_PATH}/bin/${MSVC_BUILD_TYPE}/libMathUtils.dll"
            $<TARGET_FILE_DIR:MathUtilsConsumer>
    )
endif()
