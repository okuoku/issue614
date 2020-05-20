# Override output directory
if(NOT ${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Do not use add_subdirectory here")
endif()
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

cmake_minimum_required(VERSION 3.0)
project(issue645 C)

set(CHIBI_SCHEME_SHARED ON CACHE BOOL "" FORCE)
add_subdirectory(chibi-scheme)

include_directories(chibi-scheme/include
    # Add generated include
    ${CMAKE_CURRENT_BINARY_DIR}/chibi-scheme/include)

add_definitions(-DSEXP_USE_GREEN_THREADS=0)
add_executable(check check.c)
target_link_libraries(check chibi-scheme-0.8.0 ws2_32)

