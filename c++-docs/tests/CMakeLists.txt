cmake_minimum_required(VERSION 3.5.1)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests singletonDpTest.cpp)
add_executable(simplegtest simple-gtest-example.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
