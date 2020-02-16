cmake_minimum_required(VERSION 3.0)
project(issue614 C)

add_definitions(-DSEXP_STATIC_LIBRARY) # BUG
set(CHIBI_SCHEME_SHARED OFF CACHE BOOL "" FORCE) # Use static library
add_subdirectory(chibi-scheme)

include_directories(chibi-scheme/include
    # Add generated include
    ${CMAKE_CURRENT_BINARY_DIR}/chibi-scheme/include)
add_executable(check check.c)
target_link_libraries(check chibi-scheme-0.8.0 ws2_32)
