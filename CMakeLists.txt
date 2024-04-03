cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include_directories(headerFiles)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unitTest UnitTests/dateTest.cpp headerFiles/dateHeader.cpp UnitTests/prescriptionTest.cpp headerFiles/prescriptionHeader.cpp)
target_link_libraries(unitTest ${GTEST_LIBRARIES} gtest_main pthread)
