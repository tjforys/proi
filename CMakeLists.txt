cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

# include_directories(headerFiles nlohmann)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unitTest UnitTest.cpp)
add_executable(main main.cpp)
target_link_libraries(unitTest ${GTEST_LIBRARIES} gtest_main pthread)
