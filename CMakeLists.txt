cmake_minimum_required(VERSION 3.10)

project(PQueue)

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(source)
add_subdirectory(test)









