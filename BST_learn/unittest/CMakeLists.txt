cmake_minimum_required(VERSION 2.6)

#
# This scrip automaticley find google test dependencies
# and create Makefile which compile tests
#

# set c++11 standard
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra") 

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests.out unittest.cpp)
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)
