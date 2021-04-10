cmake_minimum_required(VERSION 3.20.1)
 project(This)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
enable_testing()
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests singletonDpTest.cpp)
add_executable(simplegtest simple-gtest-example.cpp)
add_executable(gtest-mock gtest-mock-example.cpp)


#target_link_libraries(gtest-mock ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)
#target_link_libraries(gtest-mock ${GTEST_LIBRARIES} pthread)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(simplegtest ${GTEST_LIBRARIES} pthread)
target_link_libraries(gtest-mock gtest)
target_link_libraries(gtest-mock gmock)
target_link_libraries(gtest-mock pthread)