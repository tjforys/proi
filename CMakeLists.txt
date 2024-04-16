cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include_directories(headerFiles)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unitTest UnitTests/dateTest.cpp headerFiles/Date.cpp UnitTests/prescriptionTest.cpp headerFiles/Prescription.cpp)
target_link_libraries(unitTest ${GTEST_LIBRARIES} gtest_main pthread)
