cmake_minimum_required(VERSION 3.0)
project(issue645-phase1)

add_subdirectory(../chibi-scheme chibi-scheme)

install(TARGETS chibi-scheme-0.8.0
    DESTINATION lib)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../chibi-scheme/include/chibi
    DESTINATION include)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/chibi-scheme/include/chibi
    DESTINATION include)

