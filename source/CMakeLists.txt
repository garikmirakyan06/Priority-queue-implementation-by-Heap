cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)


add_executable(PQueue ${SOURCE_FILES})

target_include_directories(PQueue PUBLIC ../include)

