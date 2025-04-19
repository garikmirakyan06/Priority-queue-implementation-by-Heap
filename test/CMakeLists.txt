cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(Test test.cc)

add_subdirectory(external/googletest)


target_link_libraries(Test gtest gtest_main)
