cmake_minimum_required(VERSION 2.6)

#
# This scrip automaticley find google test dependencies
# and create Makefile which compile tests
#
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests.out google_test_example.cpp)
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)
