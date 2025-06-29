cmake_minimum_required(VERSION 3.30)
project(TheMathLib)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_GENERATOR_PLATFORM x64)  # For 64-bit build
# set(CMAKE_GENERATOR_PLATFORM Win32)  # For 32-bit

set(SOURCES src)

add_definitions(-DEXPORTING_DLL)

# Add the library target
add_library(TheMathLib SHARED ${SOURCES}/library.cpp
        ${SOURCES}/numbertheory/av.cpp)

# Optionally set properties (e.g., version, output name)


# Check if release or debug
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(TheMathLib PROPERTIES
    VERSION 1.0
    SOVERSION 1
    OUTPUT_NAME TheMathLibMSVC)

endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    set_target_properties(TheMathLib PROPERTIES
    VERSION 1.0
    SOVERSION 1
    OUTPUT_NAME TheMathLib)
endif()


set_target_properties(TheMathLib PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

