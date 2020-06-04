cmake_minimum_required(VERSION 3.0)
project(issue645-phase2)

set(tgt x64-Debug)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../out/install/${tgt}/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../out/install/${tgt}/lib)

#add_definitions(-DSEXP_USE_GREEN_THREADS=0)
add_executable(check ../check.c)
add_custom_command(TARGET check POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy 
    ${CMAKE_CURRENT_SOURCE_DIR}/../out/install/${tgt}/lib/chibi-scheme-0.8.0.dll
    ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(check chibi-scheme-0.8.0 ws2_32)
