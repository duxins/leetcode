cmake_minimum_required(VERSION 3.3)

project(leetcode)

add_subdirectory(lib/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(lib/list/include lib/list/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_library(linked_list lib/list/src/list.cpp)

function(target name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} gtest gtest_main linked_list)
endfunction(target)

target(001-two-sum)
