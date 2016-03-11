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
target(141-linked-list-cycle)
target(142-linked-list-cycle-ii)
target(021-merge-two-sorted-lists)
target(019-remove-nth-node-from-end-of-list)
target(083-remove-duplicates-from-sorted-list)
target(231-power-of-two)
target(191-number-of-1-bits)
target(326-power-of-three)
target(169-majority-element)
target(027-remove-element)
