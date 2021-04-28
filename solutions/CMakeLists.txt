project(leetcode)

cmake_minimum_required(VERSION  3.13)



add_subdirectory(headers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(leetcode_1 leetcode_1_solution_1.cc)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(leetcode_1
        ${GTEST_BOTH_LIBRARIES}
        pthread)

gtest_discover_tests(leetcode_1)