cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(dateTest UnitTest.cpp fun_definitions.cpp)
target_link_libraries(dateTest ${GTEST_LIBRARIES} gtest_main pthread)